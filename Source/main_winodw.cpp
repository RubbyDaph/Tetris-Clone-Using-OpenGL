#include "main_window.h"
#include "IconsMaterialDesign.h"

ImVec2 get_render_window_size(SDL_Window* window);
void close_window_button(SDL_Window* window , bool &done); // button to close window
void pause_button(bool &pause_menu_window); // pause menu switch
void title_text(SDL_Window* window);

void main_window_render(SDL_Window * window, bool& done , bool& pause_menu_window)
{
    ImGui::PushStyleColor(ImGuiCol_WindowBg , ImVec4(0.07f , 0.07f, 0.07f , 1.f ));
    ImGui::SetNextWindowPos(ImVec2(0.f , 0.f));
    ImGui::SetNextWindowSize(get_render_window_size(window));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding , 20.f);
    ImGui::Begin("##" , nullptr ,
                 ImGuiWindowFlags_NoResize|
                 ImGuiWindowFlags_NoTitleBar|
                 ImGuiWindowFlags_NoCollapse|
                 ImGuiWindowFlags_NoScrollbar|
                 ImGuiWindowFlags_NoBringToFrontOnFocus);
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();

    pause_button(pause_menu_window);
    title_text(window);
    close_window_button(window , done);
    ImGui::End();
}

ImVec2 get_render_window_size(SDL_Window* window)
{
    int Render_window_size_x;
    int Render_window_size_y;
    SDL_GetWindowSize(window , &Render_window_size_x , &Render_window_size_y);
    return(ImVec2(Render_window_size_x, Render_window_size_y));

}

void close_window_button(SDL_Window* window , bool &done)
{
    ImGui::SetCursorPos(ImVec2(get_render_window_size(window).x -  56, 28));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding , 100.f);

    if (ImGui::Button(ICON_MD_CLOSE  , ImVec2(40.f , 40.f)))
    {
        done = true;
    }

    ImGui::PopStyleVar();
}

void pause_button(bool &pause_menu_window)
{
    ImGui::SetCursorPos(ImVec2(16.f , 28.f));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding , 10.f);
    if (ImGui::Button("Pause" , ImVec2(80.f , 40.f)) )
    {
        pause_menu_window = true;
    }
    ImGui::PopStyleVar();
}

void title_text(SDL_Window* window)
{
    ImGui::SetCursorPos(ImVec2(get_render_window_size(window).x/2 - 30.f , 44.f));
    ImGui::Text("DooDonya");
}
