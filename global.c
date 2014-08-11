#include <stdio.h>
#include <math.h>
#include "global.h"

void draw_windows(void)
    {
    glClear(GL_COLOR_BUFFER_BIT);

    printf("call function %s!  \n", __func__);
     rect_with_board(0, 0, 2.0, windows_line_width, rect, white, black);
     glFlush();
    }

void rect_with_board(GLfloat x, GLfloat y, GLfloat f_size, GLfloat width, int squar_flag, color board[], color inside[])
    {

    float scale = 1.0;
    float _size = f_size / 2.0;
    if(squar_flag == squar) scale = windows_scale;

   // printf("call function %s!  \n", __func__);

    glColor3ubv(board);
    glBegin(GL_QUADS);

    glVertex2f(x - _size * scale , y + _size);
    glVertex2f(x + _size * scale , y + _size);
    glVertex2f(x + _size * scale , y - _size);
    glVertex2f(x - _size * scale , y - _size);

    glEnd();

    glColor3ubv(inside);
    glBegin(GL_QUADS);

    glVertex2f(x - (_size - width) * scale, y + _size - width);
    glVertex2f(x + (_size - width) * scale, y + _size - width);
    glVertex2f(x + (_size - width) * scale, y - _size + width);
    glVertex2f(x - (_size - width) * scale, y - _size + width);

    glEnd();

    }

void draw_box(GLfloat x, GLfloat y, color b_color[])
{
    rect_with_board(x, y, box_size , box_size * box_scale , 1,  black, b_color);
}

int rand_shape(void)
{
	return rand()%shape_max;
}

void draw_pre_shape(int shape_num)
{
	GLfloat X = 0.45;
	GLfloat Y = 0.62;
	GLfloat x = X;
	GLfloat y = Y;
	//先清掉上次的图像
	draw_preview();

    	printf("call function %s! shape num is %d  \n", __func__, shape_num);

        int i = 0;
	int j = 0;
	char flag = 0;
	char mask = 0x80;
	for(i = 0; i<2; i++)
		{
		flag = shapes[shape_num].box[i];
		if(i == 1) y -= box_size;
		for(j =0; j<8; j++)
			{
				if(4 == j)  y -= box_size;
				x = X + box_size_x * (j%4);
				if(flag& mask)
                    draw_box(x, y, shapes[shape_num].co );
                flag <<= 1;
			}
		}
}
void draw_board(void)
{
    int i;
    printf("call function %s!  \n", __func__);
    GLfloat y = -1.0 + 1.5 * box_size;
    for(i = 0; i < 15 ; i++)
    {
        draw_box(board_left_position, y, blue);
        draw_box(board_right_position, y, blue);
        y += box_size;
    }
}

void draw_preview(void)
{
	rect_with_board(preview_x, preview_y, preview_size, preview_line_width, squar,red, black);
}
void mydisplay(void)
    {
    glClear(GL_COLOR_BUFFER_BIT);
    draw_windows();
    draw_preview();
    //square_with_board(0,0,0.5,0.02,blue,red);
  //  draw_box(0.6, 0.4, orange);
    draw_board();
   draw_pre_shape(rand_shape());
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

