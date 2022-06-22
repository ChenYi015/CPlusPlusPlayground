# Specify cmake version minimum required
cmake_minimum_required(VERSION 3.15)

# Specify project name and programming languages
project(CPlusPlusPlayground LANGUAGES CXX)

# Specify c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable test
enable_testing()

add_subdirectory(third-party EXCLUDE_FROM_ALL)
add_subdirectory(src)
add_subdirectory(test)
