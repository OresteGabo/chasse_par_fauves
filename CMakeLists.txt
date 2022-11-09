cmake_minimum_required(VERSION 3.23)
project(chasse_par_fauves)

set(CMAKE_CXX_STANDARD 14)

add_executable(chasse_par_fauves main.cpp Position.cpp Position.h Plateau.cpp Plateau.h)
