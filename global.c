#include <stdio.h>
#include "global.h"

void draw_windows(void)
    {
    glClear(GL_COLOR_BUFFER_BIT);

     square_with_board(0, 0, 1.0, windows_line_width, blue, black);


    glFlush();
    }

void square_with_board(GLfloat x, GLfloat y, GLfloat f_size, GLfloat width, color board[], color inside[])
    {
    glColor3ubv(board);
    glBegin(GL_QUADS);

    glVertex2f(x - f_size , y + f_size);
    glVertex2f(x + f_size , y + f_size);
    glVertex2f(x + f_size , y - f_size);
    glVertex2f(x - f_size , y - f_size);

    glEnd();

    glColor3ubv(inside);
    glBegin(GL_QUADS);

    glVertex2f(x - f_size + width, y + f_size - width);
    glVertex2f(x + f_size - width, y + f_size - width);
    glVertex2f(x + f_size - width, y - f_size + width);
    glVertex2f(x - f_size + width, y - f_size + width);

    glEnd();

    }

void draw_box(int x, int y)
{
  //  square_with_board(x , y, box_size * 0.8, box_size * 0.1,  black,  white );
    int f_size = box_size * 4 / 5;
    int width = box_size / 10;
    glColor3ubv(black);
    glBegin(GL_QUADS);

    glVertex2i(x - f_size , y + f_size);
    glVertex2i(x + f_size  , y + f_size);
    glVertex2i(x + f_size  , y - f_size);
    glVertex2i(x - f_size , y - f_size);

    glEnd();

    glColor3ubv(white);
    glBegin(GL_QUADS);

    glVertex2i(x - (f_size - width) , y + f_size - width);
    glVertex2i(x + (f_size - width) , y + f_size - width);
    glVertex2i(x + (f_size - width) , y - f_size + width);
    glVertex2i(x - (f_size - width) , y - f_size + width);

    glEnd();

}

void draw_board(void)
{
    int i;
    //GLfloat x = board_left_position;
    GLfloat y = -1.0 + 0.5 * box_size;
    for(i = 0; i < 17 ; i++)
    {
        draw_box(board_left_position, y );
        draw_box(board_right_position, y );
        y += box_size;
    }
}

void mydisplay(void)
    {
    glClear(GL_COLOR_BUFFER_BIT);
  //  draw_windows();
 //   square_with_board(0,0,0.5,0.02,blue,red);
 //   draw_box(0, 0);
    //draw_board();
     glColor3ubv(white);
 glBegin(GL_LINES);
glVertex2i(100, 200);
glVertex2i(1,0);
glEnd();
    glFlush();
    }

int main(int argc, char *argv[])
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);

    glutInitWindowPosition(150, 70);
    glutInitWindowSize(windows_width, windows_height);
    glutCreateWindow("第一个绘图窗口");

    glutDisplayFunc(&mydisplay);

    glutMainLoop();
    return 0;
    }

