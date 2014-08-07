#include <stdio.h>
#include "global.h"

void draw_windows(void)
{
       	 glClear(GL_COLOR_BUFFER_BIT);
 	
	 color_set_white;//边框颜色

         glBegin(GL_QUADS);

         glVertex2f(-1.0f, 1.0f);
         glVertex2f(1.0f, 1.0f);
         glVertex2f(1.0f, -1.0f);
         glVertex2f(-1.0f, -1.0f);
 
         glEnd();


	 color_set_black;//背景颜色

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
        glutInitWindowSize(1000, 600);
        glutCreateWindow("第一个绘图窗口");

        glutDisplayFunc(&mydisplay);
        glutMainLoop();
        return 0;
}

