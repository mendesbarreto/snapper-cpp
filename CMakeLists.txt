cmake_minimum_required(VERSION 3.10)

project(snapper-cpp)

# Set the path to the OpenCV directory
set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/thirdpart/opencv-4.8.0")

# Find the OpenCV library
find_package(OpenCV REQUIRED PATHS "${OpenCV_DIR}")

# Gather your source files
file(GLOB SOURCE_FILES src/*.cpp)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link the OpenCV libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# Set the C++ standard
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 14)

