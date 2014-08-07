#include <stdio.h>
#include "global.h"

void draw_windows(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ubv(white);
    glBegin(GL_QUADS);

    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();


    glColor3ubv(black);

    glBegin(GL_QUADS);

    glVertex2f(-1.0f + windows_line_width, 1.0f- windows_line_width);
    glVertex2f(1.0f- windows_line_width, 1.0f- windows_line_width);
    glVertex2f(1.0f- windows_line_width, -1.0f+ windows_line_width);
    glVertex2f(-1.0f+ windows_line_width, -1.0f+ windows_line_width);
    glEnd();

    glFlush();
}

void mydisplay(void)
{
    draw_windows();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(windows_width, windows_height);
    glutCreateWindow("第一个绘图窗口");

    glutDisplayFunc(&mydisplay);
    glutMainLoop();
    return 0;
}

