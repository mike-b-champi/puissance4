cmake_minimum_required(VERSION 2.6)
add_definitions(-g -Wall)
project(Puissance4)
include_directories(include)
add_executable(
	puissance4
	src/main.c
	src/funct.c
	include/funct.h
	src/game_funct.c
	include/game_funct.h
)
