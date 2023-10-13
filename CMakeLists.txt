cmake_minimum_required(VERSION 3.10)

project(snapper-cpp)

file(GLOB SOURCE_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

