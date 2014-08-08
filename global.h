#ifndef GLOBLE_H
#define GLOBLE_H

#include <GL/glut.h>

typedef  GLubyte color;
//设置颜色
const color green[3] = {0,255,0};
const color red[3]= {255, 0, 0};
const color blue[3]= {0, 0, 255};
const color black[3] = {0, 0, 0};
const color white[3] = {255, 255, 255};

//定义界面窗口的大小 单位为像素点
#define windows_width 1000
#define windows_height 600
#define windows_scale (1.0*windows_height/windows_width)

//定义游戏区的大小 单位为方块
#define board_width 10
#define board_height 15

//定义窗口边界线的粗细 单位为像素比例
#define windows_line_width ( 2.0f / (board_height + 2))
//#define windows_line_width 0.04f

//定义小方块的大小,边界与大小的比值  单位为比例值 游戏区高度为15个box 在加上边界线
#define box_size_y (2.0 / ( board_height+2))
#define box_size_x (2.0 / ( board_height+2) * windows_height/ windows_width) 
#define box_scale (1.0/18)

//定义游戏区在界面中的位置，用距离左边界的距离表示  单位为像素点
#define board_left_position  -0.4
#define board_right_position (11 *  box_size_x +  board_left_position)


//定义预览窗口在界面中的位置,用中心点位置表示  单位为窗口比例位置
#define preview_x_positon 0.5
#define preview_y_positon 0.5

//定义预览窗口的大小 单位为窗口的比例位置
#define preview_height  0.5
#define preview_width   0.5

//定义预览窗口线的粗细 单位为窗口的比例
#define preview_line_width   0.02




//画界面边线和背景
void draw_windows(void);

//画游戏区
void draw_board(void);

//画预览区
void draw_preview(void);

//带边界的矩形
void square_with_board(GLfloat x, GLfloat y, GLfloat f_size, GLfloat width, color board[], color inside[]);

//画小方块 保证在4：3的窗口下是正方形
void draw_box(GLfloat x, GLfloat y);

#endif
