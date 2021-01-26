#Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(HindmarshRoseModel)

# Add all the source files needed to build the executable
add_executable(HindmarshRoseModel main.cpp src/HindmarshRoseParams.cpp src/HindmarshRoseStep.cpp src/HindmarshRoseModel.cpp) 

include_directories(getNextRungeKuta)
link_directories(getNextRungeKuta)

add_subdirectory(getNextRungeKuta)

# Link the executable and the library together
target_link_libraries(HindmarshRoseModel getNextRungeKuta)