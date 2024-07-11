cmake_minimum_required(VERSION 3.28)
project(Stratos_X C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Stratos_X
        stratos.h
        main.c
        sound_effects.c
        sleep.h
        sleep.c
        ships.h
        ships.c
        sounds.h
        sound_effects.c
        extend_def.h)
