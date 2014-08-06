#ifndef GLOBLE_H
#define GLOBLE_H

#include <GL/glut.h>

//设置颜色
#define color_set_green glColor3ub(0,255,0)
#define color_set_red glColor3ub(255, 0, 0)
#define color_set_blue glColor3ub(0, 0, 255)
#define color_set_white glColor3ub(0, 0, 0)
#define color_set_black glColor3ub(255, 255, 255)

//定义界面窗口的大小 单位为像素点
#define windows_width 1000
#define windows_height 600 

//定义窗口边界线的粗细 单位为像素点
#define windows_line_width 20

//定义游戏区的大小 单位为方块
#define board_width 10
#define board_height 15

//定义游戏区在界面中的位置，用距离左边界的距离表示  单位为窗口的比例
#define board_left_position 0.8


//定义预览窗口在界面中的位置,用中心点位置表示  单位为窗口比例位置
#define preview_x_positon 0.5
#define preview_y_positon 0.5 

//定义预览窗口的大小 单位为窗口的比例位置
#define preview_height  0.5
#define preview_width   0.5

//定义预览窗口线的粗细 单位为窗口的比例
#define preview_line_width   0.02
 

//画界面边线
void draw_windows(void);

//画游戏区
void draw_board(void);

//画预览区
void draw_preview(void);

#endif 
