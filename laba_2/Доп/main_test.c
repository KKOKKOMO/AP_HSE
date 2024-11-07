#include <GL/freeglut.h>
#include <math.h>

void drawRotatedPolygon(int n, float angle, float px, float py) {
    float angleStep = 2.0f * 3.14159265f / n; // Угол между вершинами
    float cosTheta = cos(angle);
    float sinTheta = sin(angle);

    glBegin(GL_POLYGON);
        for (int i = 0; i < n; i++) {
            // Исходные координаты вершин многоугольника (относительно центра (0, 0))
            float x = 0.5f * cos(i * angleStep);
            float y = 0.5f * sin(i * angleStep);

            // Сдвиг к центру поворота (px, py)
            float xShifted = x - px;
            float yShifted = y - py;

            // Поворот вокруг новой точки (px, py)
            float xRotated = xShifted * cosTheta - yShifted * sinTheta;
            float yRotated = xShifted * sinTheta + yShifted * cosTheta;

            // Возвращаем обратно с учетом поворота
            float xFinal = xRotated + px;
            float yFinal = yRotated + py;

            glVertex2f(xFinal, yFinal);
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Очищаем экран

    glColor3f(0.0, 0.0, 1.0);      // Синий цвет для многоугольника
    drawRotatedPolygon(6, 1.0, 0.25f, 0.25f); // Поворачиваем 6-угольник на 45° относительно точки (0.25, 0.25)
// 3.14159265 / 4
    glFlush();                     // Отправляем содержимое буфера на экран
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotated Polygon around Custom Point");

    glClearColor(1.0, 1.0, 1.0, 1.0); // Белый фон

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


