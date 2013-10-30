#ifndef WINDMILL_H
#define WINDMILL_H

#include <vector>
#include "Angel.h"
#include "cube.h"
using namespace std;

class Windmill {
  private:
    vec3 unitCube[36];
    Cube *post, *blade1, *blade2, *blade3, *blade4;
    bool isSpinning;
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
