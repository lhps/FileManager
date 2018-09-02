cmake_minimum_required(VERSION 3.12)
project(Sistemas_Operacionais)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp metodos_arquivos.cpp metodos_hd.cpp globais_metodos.cpp so_contigua.cpp so_contigua.h)
add_executable(Sistemas_Operacionais ${SOURCE_FILES})