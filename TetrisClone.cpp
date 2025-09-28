#include "glad.h"
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "imgui_impl_opengl3_loader.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <cstdio>

#if defined(_WIN32)
#include <Windows.h>
#endif

#include <GL/gl.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "main_window.h"
#include "game_window.h"
#include "IconsMaterialDesign.h"
#include <Quad_class.h>
#include <FBO.h>


void icon_font_installation(ImGuiIO& io)
{

    io.Fonts->AddFontDefault();
    float const baseFontSize = 20.0f;
    float const iconFontSize = baseFontSize;

    ImFontConfig icons_config;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.GlyphMinAdvanceX = iconFontSize;
    icons_config.GlyphOffset.y += 20.f - 13.f;
    io.Fonts->AddFontFromFileTTF( FONT_ICON_FILE_NAME_MD, iconFontSize, &icons_config );
}


void Rotate_input(const Uint8* KeyStates);
void Side_move_input(const Uint8* KeyStates);
void Drop_Input(const Uint8* KeyStates);

int main(int, char**)
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    std::srand(std::time(nullptr));

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);


    SDL_Window* window = SDL_CreateWindow(
        "Not Custom TitleBar",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        672, 772,SDL_WINDOW_OPENGL);
    //566, 772
    //SDL_SetWindowOpacity(window , 0.f);


    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    gladLoadGL();

    SDL_GL_MakeCurrent(window, gl_context);

    SDL_GL_SetSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    icon_font_installation(io);
    ImGui::StyleColorsDark();
    ImGuiStyle* style = &ImGui::GetStyle();
    style->Colors[ImGuiCol_WindowBg] = ImVec4(0.5f, 0.5f , 0.5f, 0.7f);
    style->Colors[ImGuiCol_Button] = ImVec4(0.5f, 0.5f , 0.5f, 0.7f);


    const Uint8* KeyStates = SDL_GetKeyboardState(NULL);

    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    Shader shaderProgram("Shaders/default.vert" , "Shaders/default.frag");
    Game_Quad game_quad(shaderProgram);

    game_quad.Link_instance_attributes();

    FBO FBO1(330.f , 660.f);
    //410,f , 545.f
    int timer = 0; // for a floating block on the ground
    float On_ground_timer = 0;
    bool done = false;
    bool pause_menu_window = false; // pause menu switch
    while (!done)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
        }
        FBO1.Bind();
        glViewport(0.f , 0.f , 330.f, 660.f);
        glClearColor(0.07f, 0.07f , 0.07f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT );

        Rotate_input(KeyStates);
        Side_move_input(KeyStates);
        Drop_Input(KeyStates);
        game_quad.Apply_pattern();
        game_quad.Block_fall();
        game_quad.Render(shaderProgram);
        game_quad.Push_instance_matrix();

        if (Check_All_Below())
        {
            rep_timer(On_ground_timer, timer); // from Quad_class.cpp
            if (On_ground_timer == 1)
            {
                Update_Ground();
                game_quad.Block_spawn();
            }
            On_ground_timer = 0;
        }
        else if (!Check_All_Left_Rotation() && !Check_All_Right_Rotation() && !Ishape::Check_Ceiling())
         {
            if (Check_All_Collision_Below())
                {
                    Update_Ground();
                    game_quad.Block_spawn();
                }
         }

        FBO1.Unbind();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        main_window_render(window, done , pause_menu_window);
        render_game_window(window, FBO1.FBO_texture);

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    game_quad.Delete();
    shaderProgram.Delete();
    FBO1.Delete();


    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

//-------------------------------Controls section-------------------------------//

void Rotate_Left()
{
    if (!Check_All_Below()) // without this check, it can rotate block thru the floor and cause errors
    {
        if (angle == 0)
        {
            angle = 270;
        }
        else
        {
            angle -= 90;
        }
    }
}
void Rotate_Right()
{
    if (!Check_All_Below())
    {
        if (angle == 270)
        {
            angle = 0;
        }
        else
        {
            angle += 90;
        }
    }
}
void Move_Right()
{
    if (!Check_All_Right_Rotation() && !Ishape::Check_Ceiling()) // Is block out of bounce?
    {
        if (!Check_All_Right()) // Is block touching wall to the right?
        {
            if (!Check_All_Collision_Right())// Is block touching other block?
            {
                side_move += 33;
            }
        }
    }
}
void Move_Left()
{
    if (!Check_All_Left_Rotation() && !Ishape::Check_Ceiling()) // Is block out of bounce?
    {
        if (!Check_All_Left()) // Is block touching wall to the left?
        {
            if (!Check_All_Collision_Left()) // Is block touching other block?
            {
                side_move -= 33;
            }
        }
    }
}
void Rotate_input(const Uint8* KeyStates)
{
    static bool KeyPressed_D = false;
    static bool KeyPressed_A  = false;

    bool Press_D = KeyStates[SDL_SCANCODE_D];
    bool Press_A  = KeyStates[SDL_SCANCODE_A];

    if (Press_D && !KeyPressed_D)
    {
        Rotate_Right();
    }
    if (Press_A && !KeyPressed_A)
    {
        Rotate_Left();
    }
    if (Random != OShape)
    {
        if (Check_All_Right_Rotation())
        {
            side_move -= 33;
        }
        if (Check_All_Left_Rotation())
        {
            side_move += 33;
        }
    }
    KeyPressed_D = Press_D;
    KeyPressed_A  = Press_A;
}

void Side_move_input(const Uint8* KeyStates)
{
    static bool KeyPressed_Right = false;
    static bool KeyPressed_Left = false;

    bool Press_Right = KeyStates[SDL_SCANCODE_RIGHT];
    bool Press_Left = KeyStates[SDL_SCANCODE_LEFT];

    if (Press_Right && !KeyPressed_Right)
    {
        Move_Right();
    }
    if (Press_Left && !KeyPressed_Left)
    {
        Move_Left();
    }
    KeyPressed_Right = Press_Right;
    KeyPressed_Left = Press_Left;

}

void Drop_Input(const Uint8* KeyStates)
{
    bool Press_Down = KeyStates[SDL_SCANCODE_DOWN];
    if (!Check_All_Below())
    {
        if (Press_Down)
        {
            rep += 1;
        }
    }
}