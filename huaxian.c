#include <GL/glut.h>
#include <stdio.h>
#include "global.h"

const int windows_len = 1000;
const int windwos_height = 600;
const GLfloat pix_size = 0.09f;

void rect(GLfloat x, GLfloat y)
{	
	 GLfloat lsize = pix_size / 2;
	 glColor3f(1.0f, 1.0f, 0.0f);
         glLineWidth(1.0f);
         glBegin(GL_QUADS);
                 
         
         glVertex2f(x - lsize*0.6, y + lsize);   //*.6是为了去除屏幕的宽纵比，s的方块能一正方形显示
         glVertex2f(x + lsize*0.6, y + lsize);
         glVertex2f(x + lsize*0.6, y - lsize);
         glVertex2f(x - lsize*0.6, y - lsize);
         
         glEnd();
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
