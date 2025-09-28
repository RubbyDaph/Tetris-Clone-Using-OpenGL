#include <Quad_class.h>

Vertex Quad::vertices[4] =
    {
    {{132.f, 627.f} , {0.f , 0.f}},
    {{165.f, 627.f} , {1.f , 0.f}},
    {{165.f, 660.f} , {1.f , 1.f}},
    {{132.f, 660.f} , {0.f , 1.f}}
    };
GLfloat Quad::vertices_VBO[16] =
    {
    132.f , 627.f , 0.f , 0.f,//lower left
    165.f , 627.f , 1.f , 0.f,//lower right
    165.f , 660.f , 1.f , 1.f,//upper right
    132.f , 660.f , 0.f , 1.f//upper left
    };
GLuint Quad::indices[6] =
    {
    0, 1 , 2,
    2 , 3 , 0
    };



Quad::Quad(Shader& shader_program)
:Texture("Textures/Quad_texture.jpg" , GL_TEXTURE_2D, GL_TEXTURE0 , GL_RGB,  GL_UNSIGNED_BYTE),
 vbo(),
 instance_vbo(),
 EBO()
{
    amount = 4;
    vao.Bind();

    vbo.DataBind(vertices_VBO, sizeof(vertices_VBO));
    EBO.DataBind(indices , sizeof(indices));

    vao.LinkAttrib(vbo , 0 , 2,  GL_FLOAT, 4 * sizeof(float), (void*)0);
    vao.LinkAttrib(vbo , 1 , 2,  GL_FLOAT, 4 * sizeof(float), (void*)(2 * sizeof(float)));

    vao.Unbind();
    vbo.Unbind();
    EBO.Unbind();

    Texture.texUnit(shader_program, "tex0" , 0);
}

void Quad::Render(Shader& shader_program)
{
    glm::mat4 proj = glm::ortho(0.f ,330.f , 0.f, 660.f, -1.f , 1.f);

    shader_program.Activate();
    shader_program.SetMatrix("proj" , proj);
    Texture.Bind();
    vao.Bind();
    glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 , amount);
    Texture.Unbind();
    vao.Unbind();
    glUseProgram(0);
}

void Quad::Delete()
{
    vao.Delete();
    vbo.Delete();
    EBO.Delete();
    Texture.Delete();
}

void Quad::Link_instance_attributes()
{
    vao.Bind();
    vao.LinkAttrib(instance_vbo , 2, 4, GL_FLOAT, 4 * sizeof(glm::vec4), (void*)0);
    vao.LinkAttrib(instance_vbo , 3, 4, GL_FLOAT, 4 * sizeof(glm::vec4), (void*)(1 * sizeof(glm::vec4)));
    vao.LinkAttrib(instance_vbo , 4, 4, GL_FLOAT, 4 * sizeof(glm::vec4), (void*)(2 * sizeof(glm::vec4)));
    vao.LinkAttrib(instance_vbo , 5, 4, GL_FLOAT, 4 * sizeof(glm::vec4), (void*)(3 * sizeof(glm::vec4)));

    glVertexAttribDivisor(2, 1);
    glVertexAttribDivisor(3, 1);
    glVertexAttribDivisor(4, 1);
    glVertexAttribDivisor(5, 1);;
    vao.Unbind();
}


void Quad::Push_instance_matrix()
{
    instance_vbo.Bind();
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(Instance_matrix.size() * sizeof(glm::mat4)), Instance_matrix.data(), GL_DYNAMIC_DRAW);
    instance_vbo.Unbind();
}

pattern Choose_Pattern()
    {
    using enum pattern_type;
    pattern temp;
    switch (Random)
    {
        case IShape: temp = get_Ishape();break;
        case OShape: temp = get_Oshape();break;
        case LShape: temp = get_Lshape();break;
        case JShape: temp = get_Jshape();break;
        case TShape: temp = get_Tshape();break;
        case SShape: temp = get_Sshape();break;
        case ZShape: temp = get_Zshape();break;
    }
    return temp;
    }

void Quad::Apply_pattern()
{
    Instance_matrix.resize(amount);
    pattern temp = Choose_Pattern();
    switch (angle)
    {
    case 0:
        for (int n = 0; n < 4 ; n++)
        {
            Instance_matrix[(amount - 4) + n] = temp.Facing_up[n];
        }
        break;
    case 90:
        for (int n = 0; n < 4 ; n++)
        {
            Instance_matrix[(amount - 4) + n] = temp.Facing_right[n];
        }
        break;
    case 180:
        for (int n = 0; n < 4 ; n++)
        {
            Instance_matrix[(amount - 4) + n] = temp.Facing_down[n];
        }
        break;
    case 270:
        for (int n = 0; n < 4 ; n++)
        {
            Instance_matrix[(amount - 4) + n] = temp.Facing_left[n];
        }
        break;
    }
}

void rep_timer(float& rep, int& timer)
{
    if (timer >= 60)
    {
        rep++;
        timer = 0;
    }
    timer++;
}

void Game_Quad::Block_fall()
{
    static int timer = 0; // for a falling block
    pattern temp = Choose_Pattern();
    switch (Random)
    {
    case OShape:
            Oshape::Update_pos(vertices, temp ,rep);
            if (!Oshape::Check_below())
            {
                rep_timer(rep, timer);
            }
        Update_Instance_matrix(Instance_matrix, amount);
        break;
    case IShape:
            Ishape::Update_pos(vertices, temp, rep);
            if (!Ishape::Check_below())
            {
                rep_timer(rep, timer);
            }
        Update_Instance_matrix(Instance_matrix, amount);
        break;
    case JShape:
        Jshape::Update_pos(vertices, temp, rep);
        if (!Jshape::Check_below())
        {
            rep_timer(rep, timer);
        }
        Update_Instance_matrix(Instance_matrix, amount);
        break;
    case LShape:
        Lshape::Update_pos(vertices, temp, rep);
        if (!Lshape::Check_below())
        {
            rep_timer(rep, timer);
        }
        Update_Instance_matrix(Instance_matrix, amount);
        break;
    case TShape:
        Tshape::Update_pos(vertices, temp, rep);
        if (!Tshape::Check_below())
        {
            rep_timer(rep, timer);
        }
        Update_Instance_matrix(Instance_matrix, amount);
        break;
    case SShape:
        Sshape::Update_pos(vertices, temp, rep);
        if (!Sshape::Check_below())
        {
            rep_timer(rep, timer);
        }
        Update_Instance_matrix(Instance_matrix, amount);
        break;
    case ZShape:
        Zshape::Update_pos(vertices, temp, rep);
        if (!Zshape::Check_below())
        {
            rep_timer(rep, timer);
        }
        Update_Instance_matrix(Instance_matrix, amount);
        break;
    }
}

void Game_Quad::Block_spawn()
{
    amount += 4;
    rep = 0.f;
    side_move = 0;
    angle = 0;
    Random = std::rand() % 7 + 1;
}
