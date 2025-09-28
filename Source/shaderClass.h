#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include "glad.h"
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
#include<glm.hpp>
#include<gtc/type_ptr.hpp>

std::string get_file_contents(const char* filename);
class Shader
{
public:
    GLuint ID;
    Shader(const char* vertexFile , const char* fragmentFile);

    void Activate();
    void SetMatrix(const char* name, glm::mat4& matrix);
    void Delete();
};

#endif