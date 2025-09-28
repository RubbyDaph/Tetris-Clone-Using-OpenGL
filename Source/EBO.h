#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include "glad.h"

class EBO
{
public:
    GLuint ID;
    EBO();

    void Bind();
    void DataBind(GLuint indices[], GLsizeiptr size);
    void Unbind();
    void Delete();
};

#endif
