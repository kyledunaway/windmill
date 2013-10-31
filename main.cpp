/**
* Windmill
* CSCI 566
* Kyle Dunaway
* CSC Chico
* 
* 
* main.cpp
*
**/

#include "windmill.h"

//main windmill object for program
Windmill windmill;


//function declarations before int main
int initialize(int, char**);
void displayCallback(void);
void keyboardWrapper(unsigned char, int, int);
void registerCallbacks();
void timer(int);

/**
*  main
*
*  Calls initialize, and gluttimer, along with the glutmainloop
*  
*  @param  argc
*  @param  argv
*  @return 0
**/
int main(int argc, char** argv)
{
    initialize(argc, argv);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

/**
*  initialize
*
*  glutinitialize functions, sets window, and calls registerCallbacks for program
*  @param  argc
*  @param  argv
*  @return 0
**/
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

/**
*  regsterCallbacks
*
*  sets up display and keyboard
**/
void registerCallbacks()
{
    glutDisplayFunc(displayCallback);
    glutKeyboardFunc(keyboardWrapper);
}

/**
*  displayCallback
*
*  Calls windmill.display
**/
void displayCallback() {
  windmill.display();
}

/**
*  keyboardWrapper
*
*  Calls windmill.keyboard
*  Manages the keys pressed during the program
**/
void keyboardWrapper(unsigned char keycode, int x, int y) {
  windmill.keyboard(keycode, x, y);
}

/**
*  timer
*
*  Calls windmill.tick
*  Timer function for the program to keep time.
**/
void timer(int value) {
  windmill.timer();
  glutTimerFunc(5, timer, 0);
}
