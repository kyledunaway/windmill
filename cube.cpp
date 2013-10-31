/**
* Windmill
* CSCI 566
* Kyle Dunaway
* CSC Chico
* 
* 
* cube.cpp
*
**/

#include "windmill.h"
#include "cube.h"
using namespace std;

/**
*  Cube::Cube(vec3 cube[])
*  Cube object constructor, passed a vec3 array from windmill object
*  Every cube gets the same unitcube from windmill
*  
*  Creates placeholders for cubes orientation, and sets them to zero
**/
Cube::Cube(vec3 cube[])
{
    for(int i = 0; i < 36; i++)
    {
        unitCube[i] = cube[i];
    }
    cubeX = 0.0;
    cubeY = 0.0;
    cubeZ = 0.0;
}

/**
*  void Cube::initCube()
*  Loads the shaders
**/
void Cube::initCube()
{
    cubeShader = InitShader("vertexShader.glsl", "fragmentShader.glsl");
    glUseProgram(cubeShader);
    glGenBuffers(1, &cubeVbo);
}

/**
*  void Cube::display()
*  
*  Binds buffer and locations of shader variables
*  also calls glDrawArrays for the triangles for each cube
* 
**/
void Cube::display()
{
    glUseProgram(cubeShader);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVbo);
    glBufferData(GL_ARRAY_BUFFER, 3456, &unitCube[0], GL_STATIC_DRAW);

    mat4 mainMatrix = generateMatrix();

    GLuint colorLocation = glGetUniformLocation(cubeShader, "color");
    glUniform4fv(colorLocation, 1, color);
    GLuint positionLocation = glGetAttribLocation(cubeShader, "position");
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, false, 0, 0);
    GLuint matrixLocation = glGetUniformLocation(cubeShader, "matrix");
    glUniformMatrix4fv(matrixLocation, 1, true, mainMatrix);
    glEnableVertexAttribArray(0);
    #ifdef __APPLE__  // use Mac OS X extension
    glBindVertexArrayAPPLE(0);
    #else // non-Mac OS X operating systems
    glBindVertexArray(0);
    #endif  // __APPLE__
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

/**
*  mat4 Cube::generateMatrix()
*
*  Putting this in a function made it easier to test.
*  Generates a matrix of the rotation, transformation, and scale
*  Uses Rotate functions from Angel.h
* 
**/
mat4 Cube::generateMatrix()
{
    mat4 tempMatrix;
    tempMatrix = RotateX(cubeX) * RotateY(cubeY) * RotateZ(cubeZ) * rotation * transformation * scale;

    return tempMatrix;
}

/**
*  void Cube::rotate(int degrees, int axisFlag)
*
*  Rotating of each cube, with a flag to determine
*  with axis to rotate
*  @param degrees  [int to change degree]
*  @param axisFlag [int flag for axis to rotate]
**/
void Cube::rotate(int degrees, int axisFlag)
{
    switch(axisFlag)
    {
        case 1:
            cubeX += degrees;
        break;
        case 2:
            cubeY += degrees;
        break;
        case 3:
            cubeZ += degrees;
        break;
    }
}

/**
*  void Cube::setColor(vec4 setColor)
*
*  sets the vec4 color to the value passed
*  @param setColor [color to make cube]
**/
void Cube::setColor(vec4 setColor)
{
    color = setColor;
}

/**
*  void Cube::setRotation(vec4 setRotation)
*
*  sets the rotation to the value passed
*  @param setColor [rotation to apply to cube]
**/
void Cube::setRotation(mat4 setRotation)
{
    rotation = setRotation;
}

/**
*  void Cube::setScale(vec4 setScale)
*
*  sets the scale vec4 to the value passed
*  @param setColor [scale factor of cube]
**/
void Cube::setScale(mat4 setScale)
{
    scale = setScale;
}

/**
*  void Cube::setColor(vec4 setTransformation)
*
*  sets the vec4 transformation to the value passed
*  @param setColor [transformaton to be applied to cube]
**/
void Cube::setTransformation(mat4 setTransformation)
{ 
    transformation = setTransformation; 
}
