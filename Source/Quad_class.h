#ifndef QUAD_CLASS
#define QUAD_CLASS

#include "EBO.h"
#include "Texture.h"
#include "Physics.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


class Quad
{
protected:
    static Vertex vertices[4];
    static GLuint indices[6];
    static GLfloat vertices_VBO[16];
    VAO vao;
    VBO vbo;
    VBO instance_vbo;
    EBO EBO;
    Texture Texture;

public:
    std::vector<glm::mat4> Instance_matrix;
    int amount;

    Quad(Shader& shader_program);

    void Render(Shader& shader_program);
    void Delete();

    void Link_instance_attributes();
    void Push_instance_matrix();

    void Apply_pattern();

};

class Game_Quad : public Quad
{
public:
    void Block_fall();
    void Block_spawn();
};

class Queue_Quad : public Quad
{

};
void rep_timer(float& rep, int& timer);
#endif