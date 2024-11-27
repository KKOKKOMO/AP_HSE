#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include "input_funcs.h"


#define M_PI 3.14159265358979323846
// l = 2R*sin(pi/n)
// R = l/(2*sin(pi/n))
int num_vertic;
float rotation_angle;
float circumradius;

void draw_polygon(int num_vertic, float rotation_angle, float circumradius) {
    float angel_step = (2.0f * M_PI) / num_vertic; 
    float cos_theta = cos((-rotation_angle*2.0f * M_PI)/360);
    float sin_theta = sin((-rotation_angle*2.0f * M_PI)/360);
    float coords_of_verices[15][2];

    glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
    glBegin(GL_POLYGON);                 
    for (int i = 0; i < num_vertic; i++) {
        float x = circumradius * cos(i * angel_step); 
        float y = circumradius * sin(i * angel_step); 
        coords_of_verices[i][0] = x;
        coords_of_verices[i][1] = y;
        glVertex2f(x, y); 
    }
    glEnd();

    float px = coords_of_verices[0][0];
    float py = coords_of_verices[0][1];
    for (int i = 1; i < num_vertic; i++)
    {
        if (coords_of_verices[i][1] > py || (coords_of_verices[i][1] == py && coords_of_verices[i][0] > px))
        {
            px = coords_of_verices[i][0];
            py = coords_of_verices[i][1];
        }
    }

    glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_vertic; i++)
    {
        float x = coords_of_verices[i][0];
        float y = coords_of_verices[i][1];

        //сдвигаем все точки на px py чтобы вершина была в (0,0)
        float x_shifted = x - px;
        float y_shifted = y - py;

        //считаем значения координат с помощью матрицы поворота
        float x_rotated = x_shifted * cos_theta - y_shifted * sin_theta;
        float y_rotated = x_shifted * sin_theta + y_shifted * cos_theta;
        
        //смещаем полученные координаты обратно
        float x_final = x_rotated + px;
        float y_final = y_rotated + py;

        glVertex2f(x_final, y_final);
    }
    glEnd();
}

void drawGrid() {
    glColor3f(0.8f, 0.8f, 0.8f); // Цвет линий сетки - светло-серый
    glBegin(GL_LINES);

    // Вертикальные линии сетки
    for (float x = -1.0f; x <= 1.0f; x += 0.1f) {
        glVertex2f(x, -1.0f);
        glVertex2f(x, 1.0f);
    }

    // Горизонтальные линии сетки
    for (float y = -1.0f; y <= 1.0f; y += 0.1f) {
        glVertex2f(-1.0f, y);
        glVertex2f(1.0f, y);
    }

    glEnd();
}

void drawAxes() {
    glColor3f(0.0f, 0.0f, 0.0f); 
    glLineWidth(2.0f);            
    glBegin(GL_LINES);

    // Ось X
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);

    // Ось Y
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);

    glEnd();
    glLineWidth(1.0f); // Вернем ширину линии по умолчанию
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Очищаем буфер

    drawGrid();    // Рисуем сетку
    drawAxes();    // Рисуем оси координат

    glColor4f(0.0, 0.0, 1.0, 0.5);      // Синий цвет для многоугольника
    draw_polygon(num_vertic, rotation_angle, circumradius);                // Рисуем 6-угольник

    glFlush();                     // Отправляем содержимое буфера на экран
}

int main(int argc, char **argv) {
    printf("Enter the number of angles of the polygon: ");
    num_vertic = get_valid_input_for_positive_int();
    //scanf("%d", &num_vertic);

    printf("Enter the rotation angle: ");
    rotation_angle = get_valid_input_for_float();
    //scanf("%f", &rotation_angle);

    printf("Enter circumradius (0 < circumradius <= 1): ");
    circumradius = get_valid_input_for_norm_float();
    //scanf("%f", &circumradius);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("LOLOLOLOLOL GIVE ME 10!!!!! PLS XDDDDD");

    glClearColor(1.0, 1.0, 1.0, 1.0); // Белый фон

    glEnable(GL_BLEND);               // Включаем смешивание
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
