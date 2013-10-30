#include "windmill.h"

Windmill windmill;

int initialize(int, char**);
void displayCallback(void);
void keyboardWrapper(unsigned char, int, int);
void registerCallbacks();
void timer(int);

int main(int argc, char** argv)
{
    initialize(argc, argv);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
int initialize(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Windmill");
    glClearColor(1, 1, 1, 1);
    #ifndef __APPLE__  // use glew
    glewExperimental = GL_TRUE; // JC - needed to prevent segfault
    glewInit();
    #endif  // __APPLE__
    windmill.initWindmill();
    glEnable(GL_DEPTH_TEST);
    registerCallbacks();
    return 0;
}

void registerCallbacks()
{
    glutDisplayFunc(displayCallback);
    glutKeyboardFunc(keyboardWrapper);
}
void displayCallback() {
  windmill.display();
}

void keyboardWrapper(unsigned char keycode, int x, int y) {
  windmill.keyboard(keycode, x, y);
}

void timer(int value) {
  windmill.timer();
  glutTimerFunc(5, timer, 0);
}
