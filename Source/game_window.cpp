#include "game_window.h"


void render_game_window(SDL_Window* window, GLuint& image_id)
{
    ImGui::SetNextWindowPos(ImVec2(166.f  , 90.f));
    ImGui::SetNextWindowSize(ImVec2(340.f , 665.f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding , 7.f);
    ImGui::Begin("##game_window" , nullptr ,
             ImGuiWindowFlags_NoResize|
             ImGuiWindowFlags_NoTitleBar|
             ImGuiWindowFlags_NoCollapse|
             ImGuiWindowFlags_NoScrollbar);

    ImVec2 render_size = ImVec2(330.f , 660.f);
    ImVec2 render_pos = ImVec2(5.f , 0.f);

    ImGui::SetCursorPos(render_pos);
    ImGui::Image((void*)(intptr_t)image_id, render_size);

    ImGui::End();
    ImGui::PopStyleVar(3);
}

