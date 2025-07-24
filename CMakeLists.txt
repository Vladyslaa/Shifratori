cmake_minimum_required(VERSION 3.12)
project(Shifratori)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(Shifratori
    src/main.cpp
    src/Engine.cpp
)
