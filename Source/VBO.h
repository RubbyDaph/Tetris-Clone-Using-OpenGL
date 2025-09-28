#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include "glad.h"
#include <glm.hpp>
#include <vector>
struct Vertex
{
    glm::vec2 coordinates;
    glm::vec2 tex_coordinates;
};

class VBO
{
public:
    GLuint ID;
    VBO();

    void Bind();
    void DataBind(GLfloat vertices[] , GLsizeiptr size);
    void Unbind();
    void Delete();
};

#endif
