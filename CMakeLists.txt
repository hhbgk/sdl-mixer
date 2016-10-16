cmake_minimum_required(VERSION 3.5)
project (sdl_mixer)

add_executable(mixer main.c)

#include header files' directories
include_directories(/usr/include/SDL2/)

#include dependencies libraries' directories
link_directories(/usr/lib/x86_64-linux-gnu/)

target_link_libraries(mixer SDL2 SDL2_mixer)
