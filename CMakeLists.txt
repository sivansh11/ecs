cmake_minimum_required(VERSION 3.10)

project(ecs)

set(CXX_STANDARD 20)

file(GLOB_RECURSE SRC src/*.cpp)

add_executable(ecs ${SRC})
