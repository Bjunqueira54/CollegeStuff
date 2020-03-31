#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

int xx = 0, yy = 0;
int maxx, maxy;
float r, g, b;
int isClear = 0;

void reshape(int w, int h)
{
  // Because Gil specified "screen coordinates" (presumably with an
  // upper-left origin), this short bit of code sets up the coordinate
  // system to correspond to actual window coordinates.  This code
  // wouldn't be required if you chose a (more typical in 3D) abstract
  // coordinate system.

  glViewport(0, 0, w, h);       // Establish viewing area to cover entire window.
  glMatrixMode(GL_PROJECTION);  // Start modifying the projection matrix.
  glLoadIdentity();             // Reset project matrix.
  glOrtho(0, w, 0, h, -1, 1);   // Map abstract coords directly to window coords.
  glScalef(1, -1, 1);           // Invert Y axis so increasing Y goes down.
  glTranslatef(0, -h, 0);       // Shift origin up to upper-left corner.
}

void display(void)
{
    if(isClear == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        isClear = 1;
    }
    
    for(int x = xx, y = yy; x >= 0 && y <= maxy; x--, y++)
    {
        glBegin(GL_POINTS);

        glColor3f(r, g, b);
        glVertex2i(x, y);

        glEnd();
    }
    
    glFlush();
}

void change(void)
{
    xx++;
    
    if(xx >= maxx)
    {
        xx = maxx;
        yy++;
        
        if(yy >= maxy)
        {
            xx = yy = 0;
        }
    }
    
    r = (float) rand() / RAND_MAX;
    g = (float) rand() / RAND_MAX;
    b = (float) rand() / RAND_MAX;
    
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Static");
    glutReshapeWindow(1280, 720);
    glutFullScreen();
    
    maxx = glutGet(GLUT_SCREEN_WIDTH);
    maxy = glutGet(GLUT_SCREEN_HEIGHT);

    glutDisplayFunc(display);
    
    glutReshapeFunc(reshape);
    
    glutIdleFunc(change);

    xx = yy = r = g = b = 0;
    
    srand(time(NULL));
    
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}