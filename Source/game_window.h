#pragma once
#include "imgui_impl_sdl2.h"
#include <SDL_video.h>
#include "imgui_stdlib.h"
#include "imgui.h"
#include "glad.h"
#include <cmath>
void render_game_window(SDL_Window* window, GLuint& image_id);
