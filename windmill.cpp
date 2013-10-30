#include <iostream>
#include <vector>
#include "windmill.h"
using namespace std;
Windmill::Windmill() 
{
    unitCube[0]  = vec3(-0.01,  0.01,  0.01);
    unitCube[1]  = vec3(-0.01, -0.01,  0.01);
    unitCube[2]  = vec3( 0.01,  0.01,  0.01);
    unitCube[3]  = vec3( 0.01,  0.01,  0.01);
    unitCube[4]  = vec3(-0.01, -0.01,  0.01);
    unitCube[5]  = vec3( 0.01, -0.01,  0.01);
    unitCube[6]  = vec3( 0.01,  0.01,  0.01);
    unitCube[7]  = vec3( 0.01, -0.01,  0.01);
    unitCube[8]  = vec3( 0.01,  0.01, -0.01);
    unitCube[9]  = vec3( 0.01,  0.01, -0.01);
    unitCube[10] = vec3( 0.01, -0.01,  0.01);
    unitCube[11] = vec3( 0.01, -0.01, -0.01);
    unitCube[12] = vec3( 0.01,  0.01, -0.01);
    unitCube[13] = vec3( 0.01, -0.01, -0.01);
    unitCube[14] = vec3(-0.01,  0.01, -0.01);
    unitCube[15] = vec3(-0.01,  0.01, -0.01);
    unitCube[16] = vec3( 0.01, -0.01, -0.01);
    unitCube[17] = vec3(-0.01, -0.01, -0.01);
    unitCube[18] = vec3(-0.01,  0.01, -0.01);
    unitCube[19] = vec3(-0.01, -0.01, -0.01);
    unitCube[20] = vec3(-0.01,  0.01,  0.01);
    unitCube[21] = vec3(-0.01,  0.01,  0.01);
    unitCube[22] = vec3(-0.01, -0.01, -0.01);
    unitCube[23] = vec3(-0.01, -0.01,  0.01);
    unitCube[24] = vec3(-0.01,  0.01, -0.01);
    unitCube[25] = vec3(-0.01,  0.01,  0.01);
    unitCube[26] = vec3( 0.01,  0.01, -0.01);
    unitCube[27] = vec3( 0.01,  0.01, -0.01);
    unitCube[28] = vec3(-0.01,  0.01,  0.01);
    unitCube[29] = vec3( 0.01,  0.01,  0.01);
    unitCube[30] = vec3(-0.01, -0.01,  0.01);
    unitCube[31] = vec3(-0.01, -0.01, -0.01);
    unitCube[32] = vec3( 0.01, -0.01,  0.01);
    unitCube[33] = vec3( 0.01, -0.01,  0.01);
    unitCube[34] = vec3(-0.01, -0.01, -0.01);
    unitCube[35] = vec3( 0.01, -0.01, -0.01);

    post =   new Cube(unitCube);
    blade1 = new Cube(unitCube);
    blade2 = new Cube(unitCube);
    blade3 = new Cube(unitCube);
    blade4 = new Cube(unitCube);

    isSpinning = true;
}

Windmill::~Windmill() 
{}

void Windmill::initWindmill() 
{
  post->setRotation(RotateZ(0));
  post->setScale(Scale(5, 50, 5));
  post->setTransformation(Translate(0, -.5, .1));
  post->setColor(vec4(1, 0, 0, 1));

  blade1->setRotation(RotateZ(90));
  blade1->setScale(Scale(5, 40, 5));
  blade1->setTransformation(Translate(0, .45, 0));
  blade1->setColor(vec4(1, 1, 0, 1));

  blade2->setRotation(RotateZ(180));
  blade2->setScale(Scale(5, 40, 5));
  blade2->setTransformation(Translate(0, .45, 0));
  blade2->setColor(vec4(0, 1, 0, 1));

  blade3->setRotation(RotateZ(270));
  blade3->setScale(Scale(5, 40, 5));
  blade3->setTransformation(Translate(0, .45, 0));
  blade3->setColor(vec4(0, 0, 1, 1));

  blade4->setRotation(RotateZ(360));
  blade4->setScale(Scale(5, 40, 5));
  blade4->setTransformation(Translate(0, .45, 0));
  blade4->setColor(vec4(0, 1, 1, 1));

  post->initCube();
  blade1->initCube();
  blade2->initCube();
  blade3->initCube();
  blade4->initCube();

}

void Windmill::display() {
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  post->display();

  if(isSpinning)
  {
    blade1->rotate(1, 3);
    blade2->rotate(1, 3);
    blade3->rotate(1, 3);
    blade4->rotate(1, 3);  
  }
  
  blade1->display();
  blade2->display();
  blade3->display();
  blade4->display();

  glutSwapBuffers();
}

void Windmill::keyboard(unsigned char keycode, int x, int y) 
{
    switch(keycode) {
    case 033:
        exit(EXIT_SUCCESS);
        break;
    case 'r':
        isSpinning = false;
        post =   new Cube(unitCube);
        blade1 = new Cube(unitCube);
        blade2 = new Cube(unitCube);
        blade3 = new Cube(unitCube);
        blade4 = new Cube(unitCube);
        initWindmill();
       break;
    case 's':
        if(isSpinning == true)
            isSpinning = false;
        else
            isSpinning = true;
       break;
     case 'y':
        post->rotate(5, 2);
        blade1->rotate(5, 2);
        blade2->rotate(5, 2);
        blade3->rotate(5, 2);
        blade4->rotate(5, 2);

        initWindmill();
       break;
    }
}

void Windmill::timer()
{
    display();
}