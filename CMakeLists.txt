cmake_minimum_required(VERSION 3.10)
option(LATEST_OPEN_CV "If this option is true it will select the latest opencv to test your project" OFF)

project(snapper-cpp)

if(LATEST_OPEN_CV)
  #Include latest version of open-cv
  find_package(OpenCV REQUIRED)
else()
  set(LDFLAGS "-L/opt/homebrew/opt/opencv@3/lib")
  set(CPPFLAGS "-I/opt/homebrew/opt/opencv@3/include")
  set(OpenCV_DIR "/opt/homebrew/opt/opencv@3")
  set(OpenCV_INCLUDE_DIRS "/opt/homebrew/opt/opencv@3/include")
  find_package(OpenCV 3.4 REQUIRED PATHS "${OpenCV_DIR}")
endif()


#find_package(OpenCV REQUIRED)

# Gather your source files
file(GLOB SOURCE_FILES src/*.cpp)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link the OpenCV libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# Set the C++ standard
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 14)

