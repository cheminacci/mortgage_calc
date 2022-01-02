cmake_minimum_required(VERSION 3.22)

# set the project name
project(mortgage)

# specify C standard
set(CMAKE_C_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED True)

# specify compiler flags
set(CMAKE_C_FLAGS "-lm -Wall -Wextra -Werror -Wpedantic -Wunused -Wconversion")

# add the executable
add_executable(mortgage calcmortgage.cpp)

