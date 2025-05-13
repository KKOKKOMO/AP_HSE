#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

Point points[MAX_POINTS];
int n;
double minX = -1, maxX = 10;
double minY = -1, maxY = 10;

double lagrange(Point *points, int n, double x) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = points[i].y;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x - points[j].x) / (points[i].x - points[j].x);
            }
        }
        result += term;
    }
    return result;
}

void getLagrangeCoefficients(Point* points, int n, double* coeffs) {
    for (int i = 0; i < n; i++)
        coeffs[i] = 0.0;

    for (int i = 0; i < n; i++) {
        double li[MAX_POINTS] = {1.0}; // li[0] = 1
        int degree = 1;

        for (int j = 0; j < n; j++) {
            if (j == i) continue;

            double denom = points[i].x - points[j].x;
            for (int k = degree; k >= 1; k--) {
                li[k] = li[k] / denom - li[k - 1] * points[j].x / denom;
            }
            li[0] = -li[0] * points[j].x / denom;
            degree++;
        }

        for (int k = 0; k < n; k++) {
            coeffs[k] += li[k] * points[i].y;
        }
    }
}

void printPolynomial(double* coeffs, int n) {
    printf("Standard form polynomial:\nP(x) = ");
    for (int i = 0; i < n; i++) {
        if (fabs(coeffs[i]) < 1e-8) continue;
        if (i > 0 && coeffs[i] >= 0) printf(" + ");
        else if (coeffs[i] < 0) printf(" - ");
        printf("%.4lf", fabs(coeffs[i]));
        if (i >= 1) printf("*x");
        if (i >= 2) printf("^%d", i);
    }
    printf("\n");
}

void inputPoints() {
    int choice;
    printf("1. Enter points manually\n2. Generate random points\nChoice: ");
    scanf("%d", &choice);

    printf("Enter the number of points: ");
    scanf("%d", &n);

    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            printf("Point %d (x y): ", i + 1);
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
    } else {
        for (int i = 0; i < n; i++) {
            points[i].x = i;
            points[i].y = rand() % 10;
        }
    }

    minX = points[0].x;
    maxX = points[0].x;
    minY = points[0].y;
    maxY = points[0].y;

    for (int i = 1; i < n; i++) {
        if (points[i].x < minX) minX = points[i].x;
        if (points[i].x > maxX) maxX = points[i].x;
        if (points[i].y < minY) minY = points[i].y;
        if (points[i].y > maxY) maxY = points[i].y;
    }

    double dx = (maxX - minX) * 0.2;
    double dy = (maxY - minY) * 0.2;
    minX -= dx;
    maxX += dx;
    minY -= dy;
    maxY += dy;
}

void drawGrid(double step) {
    glColor3f(0.9, 0.9, 0.9);
    glLineWidth(1.0);

    glBegin(GL_LINES);

    for (double x = floor(minX); x <= maxX; x += step) {
        glVertex2f(x, minY);
        glVertex2f(x, maxY);
    }

    for (double y = floor(minY); y <= maxY; y += step) {
        glVertex2f(minX, y);
        glVertex2f(maxX, y);
    }

    glEnd();
}

void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *text);
        text++;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(minX, maxX, minY, maxY);

    drawGrid(1.0);

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_LINES);
    glVertex2f(minX, 0);
    glVertex2f(maxX, 0);
    glVertex2f(0, minY);
    glVertex2f(0, maxY);
    glEnd();


    glColor3f(0.2, 0.6, 1.0);
    glBegin(GL_LINE_STRIP);
    for (double x = minX; x <= maxX; x += 0.01) {
        double y = lagrange(points, n, x);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
glPointSize(6.0);
glBegin(GL_POINTS);
for (int i = 0; i < n; i++) {
    glVertex2f(points[i].x, points[i].y);
}
glEnd();


glColor3f(0.0, 0.0, 0.0);
for (int i = 0; i < n; i++) {
    char label[64];
    snprintf(label, sizeof(label), "(%.1f, %.1f)", points[i].x, points[i].y);
    drawText(points[i].x + 0.1, points[i].y + 0.1, label);
}

    glutSwapBuffers();
}

int main() {
    inputPoints();

    double coeffs[MAX_POINTS];
    getLagrangeCoefficients(points, n, coeffs);
    printPolynomial(coeffs, n);

    printf("Lagrange interpolation polynomial:\nP(x) = ");
    for (int i = 0; i < n; i++) {
        printf("(%.2lf", points[i].y);
        for (int j = 0; j < n; j++) {
            if (j != i) {
                printf(" * (x - %.2lf)/%.2lf", points[j].x, points[i].x - points[j].x);
            }
        }
        if (i != n - 1) printf(") + ");
        else printf(")");
    }
    printf("\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lagrange Interpolation Polynomial");
    glutDisplayFunc(display);
    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return 0;
}