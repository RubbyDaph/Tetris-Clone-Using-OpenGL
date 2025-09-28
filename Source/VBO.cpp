#include "VBO.h"

VBO::VBO()
{
    glGenBuffers(1 , &ID);
}

void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER , ID);
}

void VBO::DataBind(GLfloat vertices[], GLsizeiptr size)
{
    glBindBuffer(GL_ARRAY_BUFFER , ID);
    glBufferData(GL_ARRAY_BUFFER, size , vertices , GL_STATIC_DRAW);
}


void VBO::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER , 0);
}

void VBO::Delete()
{
    glDeleteBuffers(1, &ID);
}