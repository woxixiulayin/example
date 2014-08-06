#include <stdio.h>
#include "global.h"

void draw_windows(void)
{
       	 glClear(GL_COLOR_BUFFER_BIT);
 	
	 color_set_blue;

         glLineWidth(windows_line_width);

         glBegin(GL_LINE_LOOP);

         glVertex2f(-1.0f, 1.0f);
         glVertex2f(1.0f, 1.0f);
         glVertex2f(1.0f, -1.0f);
         glVertex2f(-1.0f, -1.0f);
 
         glEnd();

         glFlush();
}

