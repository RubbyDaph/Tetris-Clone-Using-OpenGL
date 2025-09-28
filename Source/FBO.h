#ifndef FBO_CLASS_H
#define FBO_CLASS_H

#include <glad.h>
#include <iostream>
class FBO
{
public:
    GLuint ID;
    GLuint FBO_texture;
    FBO(float width , float height);

    void Bind();
    void Unbind();
    void Delete();
};

#endif