#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in mat4 instance_matrix;

out vec2 texCoord;

//uniform mat4 transmat;
uniform mat4 proj;


void main()
{
    vec4 pos = vec4(aPos.x , aPos.y , 0.f , 1.f);
    gl_Position = proj * instance_matrix * pos;
    gl_Position.y = -gl_Position.y;
    texCoord = aTex;
}

