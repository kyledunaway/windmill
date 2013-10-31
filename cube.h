/**
* Windmill
* CSCI 566
* Kyle Dunaway
* CSC Chico
* 
* 
* cube.h
*
**/

#ifndef CUBE_H
#define CUBE_H
using namespace std;

class Cube
{
    //private variables and functions
    private:
        vec3 unitCube[36];
        GLuint cubeShader, cubeVbo;
        int cubeX, cubeY, cubeZ;
        mat4 transformation, scale, rotation;
        vec4 color;

    //public variables and functions
    public:

        Cube(vec3 unitCube[]);
        void initCube();
        void display();
        void rotate(int degrees, int axisFlag);
        void setColor(vec4 setColor);
        void setRotation(mat4 setRotation);
        void setScale(mat4 setScale);
        void setTransformation(mat4 setTransformation);
        mat4 generateMatrix();
};

#endif
