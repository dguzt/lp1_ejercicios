cmake_minimum_required(VERSION 3.12)
project(preg03)

set(CMAKE_CXX_STANDARD 14)

add_executable( preg03 main.cpp Bib_Func_ExtraccionesF.cpp Bib_Func_ExtraccionesF.h
                Bib_Func_Provincias.cpp Bib_Func_Provincias.h
                Biblioteca_Func_Incendios.cpp Biblioteca_Func_Incendios.h)