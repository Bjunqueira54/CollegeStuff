#include <GL/glut.h>

int xx = 0, yy = 0;
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
    
    for(yy = 0; yy <= 720; yy++)
    {
        for(xx = 0; xx <= 1280; xx++)
        {
            r = (float)rand() / (float)RAND_MAX;
            g = (float)rand() / (float)RAND_MAX;
            b = (float)rand() / (float)RAND_MAX;
            
            glBegin(GL_POINTS);
    
            glColor3f(r, g, b);
            glVertex2i(xx, yy);

            glEnd();
        }
    }
    
    glFlush();
}

void change(void)
{
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Static");
    glutReshapeWindow(1280, 720);

    glutDisplayFunc(display);
    
    glutReshapeFunc(reshape);
    
    glutIdleFunc(change);

    xx = 0;
    yy = 0;
    
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}