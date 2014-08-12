#ifndef GLOBLE_H
#define GLOBLE_H
#include <GL/glut.h>
#include <unistd.h>

//定义延迟函数
#define delay_s(n)  sleep(n)
#define delay_ms(n) usleep((n)*1000)

//定义界面窗口的大小 单位为像素点
#define windows_width 1000
#define windows_height 600
#define windows_scale (1.0*windows_height/windows_width)

//定义游戏区的大小 单位为方块
#define board_width 10
#define board_height 15

//定义游戏区的背景颜色和边框颜色
#define back_color black
#define board_color white


//定义窗口边界线的粗细 单位为像素比例
#define windows_line_width ( 2.0f / (board_height + 2))
//#define windows_line_width 0.04f

//定义小方块的大小,边界与大小的比值  单位为比例值 游戏区高度为15个box 在加上边界线
#define box_size (2.0 / ( board_height+2))
#define box_scale (1.0/18)
#define box_size_y  box_size
#define box_size_x box_size*windows_scale
//定义游戏区在界面中的位置，用距离左边界的距离表示  单位为像素点
#define board_left_position  -0.6
#define board_right_position (11 * box_size * windows_height / windows_width +  board_left_position)


//定义预览窗口的大小和位置  单位为窗口的比例位置
#define preview_size  0.6
#define preview_x   0.54
#define preview_y   0.45
#define preview_shape_x preview_x-0.09
#define preview_shape_y preview_y+0.17

//定义预览窗口线的粗细 单位为窗口的比例
#define preview_line_width   0.01

//定义正方形和矩形的宏变量值
#define squar 1
#define rect 0

//定义形状的数量
#define shape_max 19

//定义绘制或者删除的宏定义
#define draw_flag 1
#define delete_flag 0


//定义键值
#define left
#define right
#define down
#define transform

typedef  GLubyte color;
//设置颜色
const color green[3] = {0,255,0};
const color red[3]= {255, 0, 0};
const color blue[3]= {0, 0, 255};
const color black[3] = {0, 0, 0};
const color white[3] = {0xff,0xff,0xfb};
const color orange[3] = {0xf1, 0x5a, 0x22};
const color yellow[3] = {0xff, 0xd4, 0x00};
const color purple[3] = {0x85, 0x52, 0xa1};
const color brown[3] = {0x53, 0x26, 0x1f};


//定义游戏区底板
struct board{
	int val;  //0表示不显示  1表示显示
	color col;  //表示该点的颜色
}table_boad[board_width][board_height];

//定义方块的结构体
struct shape{
	char box[2];
        const	color *co;//方块的颜色
	int next; //该放快下一个形状所在的索引号
}shape;

//定义带坐标的方块
typedef struct{
	int x; //在board内的整数坐标位置
	int y;
	int shape_num ;
}xyshape;

const struct shape shapes[shape_max] = {
	/*   口口
       口口   x0.5  y0*/
	{0x6c,0x0, yellow,1},
/*   口
       口口
           口    */

	{0x8c,0x40, yellow, 0},
	/*  口口
	          口口     */
	{0xc6,0x0, blue, 3},

	/*  口
	  口口
	  口   */
	{0x4c,0x80, blue, 2},

	/*
 	  口口
	  口口    */
	{0x0c,0xc0, orange, 4},

	/*
	  口口口
	  口     */
	{0x0e,0x80, red, 6},

	/*口
	  口
	  口口   */
	{0x88,0xc0, red, 7},

	/*
	          口
	  口口口   */
	{0x01,0x70, red, 8},

	/*
	  口口
	    口
	    口   */
	{0x0c,0x44, red, 5},

	/*
	  口口口
	          口   */
	{0x0e,0x20, brown, 10},

	/*
	    口口
	    口
	    口	 */
	{0x0e,0x88, brown, 11},

	/*
	  口
	  口口口   */
	{0x08,0xe0, brown, 12},

	/*    口
	        口
	    口口   */
	{0x44,0xc0, brown, 9},

	/*
    口口口
        口  */
	{0x0e,0x40, green, 14},

	/*
	      口
	      口口
	      口   */
	{0x04,0x64, green, 15},

	/*
           口
	   口口口
	       */
	{0x04,0xe0, green, 16},

	/*
            口
	    口口
	        口   */
	{0x02,0x32, green, 13},

 /*    口
	     口
	     口
         口  */
	{0x44,0x44, purple, 18},

	/*

	  口口口口
               */
	{0x00,0xf0, purple, 17},



};

//画界面边线和背景
void draw_windows(void);

//画游戏区
void draw_board(void);

//画预览区
void draw_preview(void);

//带边界的矩形 squar_flag表示是否是正方形，因为该矩形采用GLfloat定义会随着窗口尺寸变化，
void rect_with_board(GLfloat x, GLfloat y, GLfloat f_size, GLfloat width,int squar_flag, color board[], color inside[]);

//画小方块 保证在4：3的窗口下是正方形
void draw_box(GLfloat x, GLfloat y, color b_color[]);

//产生随机shape 返回值为 shapes数组中的索引号
int rand_shape(void);

//绘制或者擦除shape
void draw_or_delete_shape(GLfloat x, GLfloat y,int shape_num, int flag);

//绘制或者游戏区的shape
void draw_or_delete_board_shape(xyshape *p, int flag);

//在预览区绘制shape
//void draw_pre_shape(GLfloat x, GLfloat y,int shape_num);

//显示字符串
void show_string(GLfloat x, GLfloat y, char* p, color *col);

//显示游戏初始画面
void game_init(void);

//对shape进行变形返回变形后的shape指针
shape* shape_transform(shape *shape_tran, int key_num);

#endif
