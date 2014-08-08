#include <stdio.h>
#include "global.h"

void draw_windows(void)
    {
    glClear(GL_COLOR_BUFFER_BIT);

     square_with_board(0, 0, 1.0, windows_line_width, white, black);


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

void draw_box(GLfloat x, GLfloat y)
{
  //  square_with_board(x , y, box_size * 0.8, box_size * 0.1,  black,  white );
    //注意此处的长和宽应该是除以2之后的，以中心坐标来计算4个角的坐标,且边界与大小的比为1/10
    GLfloat f_size_x = box_size_x / 2;
    GLfloat f_size_y = box_size_y / 2;
    GLfloat width_x = box_size_x * box_scale;
    GLfloat width_y = box_size_y * box_scale;

    glColor3ubv(black);
    glBegin(GL_QUADS);

    glVertex2f(x - f_size_x, y + f_size_y);
    glVertex2f(x + f_size_x , y + f_size_y);
    glVertex2f(x + f_size_x  , y - f_size_y);
    glVertex2f(x - f_size_x , y - f_size_y);

    glEnd();

    glColor3ubv(white);
    glBegin(GL_QUADS);

    glVertex2f(x - (f_size_x - width_x) , y + f_size_y - width_y);
    glVertex2f(x + (f_size_x - width_x) , y + f_size_y - width_y);
    glVertex2f(x + (f_size_x - width_x) , y - f_size_y + width_y);
    glVertex2f(x - (f_size_x - width_x) , y - f_size_y + width_y);

    glEnd();

}

void draw_board(void)
{
    int i;
    //GLfloat x = board_left_position;
    printf("begin function %s!  \n", __func__);
    GLfloat y = -1.0 + 0.5 * box_size_y;
    for(i = 0; i < 17 ; i++)
    {
        draw_box(board_left_position, y );
        draw_box(board_right_position, y );
        y += box_size_y;
    }
}

void mydisplay(void)
    {
    glClear(GL_COLOR_BUFFER_BIT);
    draw_windows();
    //square_with_board(0,0,0.5,0.02,blue,red);
    draw_box(0, 0);
    draw_board();
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

