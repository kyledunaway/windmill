#include <vector>
#include "windmill.h"
#include "cube.h"
using namespace std;


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

void Cube::initCube()
{
    cubeShader = InitShader("vertexShader.glsl", "fragmentShader.glsl");
    glGenBuffers(1, &cubeVbo);
}

void Cube::display()
{
    glUseProgram(cubeShader);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVbo);
    glBufferData(GL_ARRAY_BUFFER, 3456, &unitCube[0], GL_STATIC_DRAW);
    mat4 mainMatrix = RotateX(cubeX) * RotateY(cubeY) * RotateZ(cubeZ) * rotation * transformation * scale;
    GLuint colorLocation = glGetUniformLocation(cubeShader, "color");
    glUniform4fv(colorLocation, 1, color);
    GLuint positionLocation = glGetAttribLocation(cubeShader, "position");
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, false, 0, 0);
    GLuint matrixLocation = glGetUniformLocation(cubeShader, "matrix");
    glUniformMatrix4fv(matrixLocation, 1, true, mainMatrix);
    glEnableVertexAttribArray(0);
    glBindVertexArrayAPPLE(0);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

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

void Cube::setColor(vec4 setColor)
{
    color = setColor;
}

void Cube::setRotation(mat4 setRotation)
{
    rotation = setRotation;
}

void Cube::setScale(mat4 setScale)
{
    scale = setScale;
}

void Cube::setTransformation(mat4 setTransformation)
{ 
    transformation = setTransformation; 
}
