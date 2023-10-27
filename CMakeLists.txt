cmake_minimum_required(VERSION 3.26)
project(ED_Codes)

set(CMAKE_CXX_STANDARD 14)

include_directories(listaDeEx1)

add_executable(ED_Codes
        ExerciciosGrafos/listaDE.h
        ExerciciosGrafos/ex2.cpp
)
