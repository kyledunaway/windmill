/**
* Windmill
* CSCI 566
* Kyle Dunaway
* CSC Chico
* 
* 
* windmill.h
*
**/

#ifndef WINDMILL_H
#define WINDMILL_H

#include "Angel.h"
#include "cube.h"
using namespace std;

class Windmill
{
    //private variables and functions
    private:
        vec3 unitCube[36];
        Cube *post, *blade1, *blade2, *blade3, *blade4;
        bool isSpinning;

    //public variables and functions
    public:
        Windmill();
        ~Windmill();
        void initWindmill();
        void display();
        void keyboard(unsigned char keycode, int, int);
        void timer();
        vec3 getUnitCube();
};

#endif
