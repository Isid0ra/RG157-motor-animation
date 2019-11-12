#include <stdlib.h>
#include <GL/glut.h>


static int window_width, window_height;


static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Motor animation");

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(3);

    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    }
}

static void on_reshape(int width, int height)
{
    window_width = width;
    window_height = height;
}

static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, window_width, window_height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,window_width/(float)window_height, 1, 5);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            2, 2, 2,
            0, 0, 0,
            0, 1, 0
        );

    /* Iscrtavanje koordinatnog sistema. */
    
    glColor3f(0, 0, 0.75);
    glBegin(GL_LINES);
    glVertex3f(0,0,100);
    glVertex3f(0,0,0);
    glEnd();
    
    glColor3f(0.70, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(100,0,0);
    glVertex3f(0,0,0);
    glEnd();
    
    glColor3f(0, 0.65, 0);
    glBegin(GL_LINES);
    glVertex3f(0,100,0);
    glVertex3f(0,0,0);
    glEnd();

    glutSwapBuffers();
}
