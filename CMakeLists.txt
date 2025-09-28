cmake_minimum_required(VERSION 3.31)
project(TetrisClone)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

file(GLOB ImGui_files
        ImGui_Framework_files/*.cpp)

file(GLOB Source_files
        Source/*.cpp)

add_executable(TetrisClone
        ImGui_Framework_files/glad.c
        ${ImGui_files}
        ${Source_files}
        TetrisClone.cpp
        )
target_include_directories(TetrisClone PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ImGui_Framework_files
        ${CMAKE_CURRENT_SOURCE_DIR}/Source
        "C:/SDL2/SDL2-devel-2.32.8-mingw/SDL2-2.32.8/x86_64-w64-mingw32/include/SDL2"
        "C:/GLM/glm"
)
target_link_directories(TetrisClone PRIVATE
        "C:/MinGW/bin"
        "C:/MinGW/lib"
        "C:/SDL2/SDL2-devel-2.32.8-mingw/SDL2-2.32.8/x86_64-w64-mingw32/lib"
)
target_link_libraries(TetrisClone PRIVATE
        SDL2
        opengl32
)