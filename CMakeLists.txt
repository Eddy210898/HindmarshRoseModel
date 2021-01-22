# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(HindmarshRosehModel)

# Add a library to this build. The name of the library is MyLibrary and it
# consists of only the MyLibrary.cpp file
add_library(HindmarshRosehModel src/HindmarshRosehParams.cpp src/HindmarshRosehStep.cpp src/HindmarshRosehModel.cpp)

link_directories(getNextRungeKuta)

add_subdirectory(getNextRungeKuta)

# Link the executable and the library together
target_link_libraries(HindmarshRosehModel getNextRungeKuta)