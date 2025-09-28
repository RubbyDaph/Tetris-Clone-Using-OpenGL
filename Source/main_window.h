#pragma once
#include "imgui_impl_sdl2.h"
#include <SDL_video.h>
#include "imgui_stdlib.h"
#include "imgui.h"

void main_window_render(SDL_Window * window, bool& done , bool& pause_menu);

