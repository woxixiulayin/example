#include <stdio.h>
#include <math.h>
#include <string.h>
#include "global.h"


// xyshape shape_next = shapes[10];  //
xyshape shape_now = {5,15,10};
static int speed = 500;//500ms

//在边界撒上要标记边界boald 的val
struct board table_board[board_width][board_height];
//memset(table_boad, 0,sizeof(table_boad));


void table_board_init(void)
{
  memset(table_board,0,sizeof(table_board));
}

void draw_windows(void)
    {
    glClear(GL_COLOR_BUFFER_BIT);

    printf("call function %s!  \n", __func__);
     rect_with_board(0, 0, 2.0, windows_line_width, rect, board_color, back_color);
     glFlush();
    }

void show_string(GLfloat x, GLfloat y, char *p, color *col)
{
	char *q = p;
	int n = strlen(q);
	int i;
        glColor3ubv(col);
	glRasterPos2f(x,y);
	//逐个显示字符串中的每个字符
	for (i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *(q+i));
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

void draw_or_delete_shape(GLfloat x, GLfloat y,int shape_num, int flag)
{
    if(draw_flag == flag)	printf("call function %s! draw shape num is %d  \n", __func__, shape_num);
    if(delete_flag == flag)	printf("call function %s! delete shape num is %d  \n", __func__, shape_num);
        int i = 0;
	int j = 0;
	char p = 0;
	char mask = 0x80;
	for(i = 0; i<2; i++)
		{
		p  = shapes[shape_num].box[i];
		if(i == 1) y -= box_size;
		for(j =0; j<8; j++)
			{
				if(4 == j)  y -= box_size;
				if(p & mask)
					{
                  		  	if(draw_flag == flag)	draw_box(x+box_size_x*(j%4), y, shapes[shape_num].co);
					else if(delete_flag == flag) 	draw_box(x+box_size_x*(j%4), y, back_color);
					 }
              			  p  <<= 1;
			}
		}
     glFlush();
}

void draw_or_delete_board_shape(xyshape *p, int flag)
{
	GLfloat x;
	GLfloat y;

	x = board_left_position + (p->x) * box_size_x;
	y = -1.0 + (1.5 + p->y) * box_size_y;

	draw_or_delete_shape(x, y, p->shape_num, flag);
    glFlush();
}

void draw_board(void)
{
    int i;
    color *co;

    printf("call function %s!  \n", __func__);
    GLfloat y = -1.0 + 1.5 * box_size_y;
    for(i = 0; i < 15 ; i++)
    {
    co = color_list[rand()%8+1];
        draw_box(board_left_position, y,co);
        draw_box(board_right_position, y,co);
        y += box_size_y;
    }
     glFlush();
}


void game_init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw_windows();
    draw_preview();
    draw_board();
    show_string(-0.35,0.2,"Teris By Liu", red);
    show_string(-0.35,0," exit (Esc) ", green);
    show_string(-0.4,-0.1,"start game (Enter)", yellow);
    glFlush();
}
void draw_preview(void)
{
	rect_with_board(preview_x, preview_y, preview_size, preview_line_width, squar,red, back_color);
     glFlush();
}

int shape_transform(xyshape *shape_tran, int key_num)
{
	int x;
	int y;
	xyshape _shape = {
                shape_tran->x,
                shape_tran->y,
                shape_tran->shape_num};

	switch(key_num)
	{
		case left:  _shape.x-- ;break;
		case right: _shape.x++;break;
		case down: _shape.y--;break;
		case up:    _shape.y++;break;
		case transform: _shape.shape_num = shapes[_shape.shape_num].next;break;
		default:return;
	}

    int i = 0;
	int j = 0;
	char p = 0;
	char mask = 0x80;
	x = _shape.x;
	y = _shape.y;
	for(i = 0; i<2; i++)
		{
		p = shapes[_shape.shape_num].box[i];
		if(i == 1) y-- ;
		for(j =0; j<8; j++)
			{
				if(4 == j)  y-- ;
				x = _shape.x + j%4;
				if(p & mask)
					{
					if(x<1||x>10||y<0||y>14)//边界处理
					{
					    if(down == key_num) return touched;
					    else return outboard;
					}
                  		  	if(1 == table_board[x][y].val)
                  		  	{
                  		  	    if(down == key_num) return touched;
                  		  	    else return hasshape;
                  		  	}
                //在没有触地前不要将其映射到table上，只需要绘制出来即可
				//	table_board[x][y].val= 1;
					//table_board[x][y].col= shapes[_shape.shape_num].co;
					 }
              			  p  <<= 1;
			}
			}

    draw_or_delete_board_shape(shape_tran,delete_flag);
    shape_tran->x = _shape.x;
    shape_tran->y = _shape.y;
    shape_tran->shape_num = _shape.shape_num;
    draw_or_delete_board_shape(shape_tran,draw_flag);
    return OK;
}
void draw_pre_shape(int shape_num)
{
	draw_preview();
    	draw_or_delete_shape(preview_shape_x,preview_shape_y,shape_num,draw_flag);
	glFlush();
}
void re_draw(void)
{
	/*static int i = 0;
	if(i>=19) i = 0;
	draw_pre_shape(i++);*/
       // draw_board();
    if(touched == shape_transform(&shape_now,down))
    {
        shape_now.x = 5;
        shape_now.y = 15;
        shape_now.shape_num = rand_shape();
        draw_or_delete_board_shape(&shape_now,draw_flag);
    }
    glutTimerFunc(speed,re_draw,1);

}

void keyprocess(unsigned char key_num, int x, int y)
{
    printf("press key is %c %d \n", key_num,key_num);
    if(esc == key_num) draw_pre_shape(rand_shape());
    //else if ( down == key_num ) return;
    else shape_transform(&shape_now, key_num);
}
void mydisplay(void)
    {
    glClear(GL_COLOR_BUFFER_BIT);
    game_init();
    draw_or_delete_board_shape(&shape_now,draw_flag);
 //   delay_ms(900);
    //delay_ms(900);
    glFlush();
    }

int main(int argc, char *argv[])
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);


    glutInitWindowPosition(150, 70);
    glutInitWindowSize(windows_width, windows_height);
    glutCreateWindow("第一个绘图窗口");

    table_board_init();

    glutTimerFunc(speed,re_draw,1);
    glutKeyboardFunc(keyprocess);

    glutDisplayFunc(&mydisplay);



    glutMainLoop();
    return 0;
    }


