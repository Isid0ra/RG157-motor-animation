#include <stdlib.h>
#include <GL/glut.h>


static int window_width, window_height;


static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void init(void);


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

    glLineWidth(3);

    init();
    glutMainLoop();

    return 0;
}

static void init(void)
{
    
    GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1 };
    GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1 };
    GLfloat light_specular[] = { 0.5, 0.5, 0.5, 1 };

    glClearColor(0, 0, 0, 0);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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
