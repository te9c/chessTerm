cmake_minimum_required(VERSION 3.22)

project(
    chessCMD
    VERSION 0.1
    DESCRIPTION "chess TUI on c++"
    LANGUAGES CXX)

# Error when building in src folders
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with "
                        "CMakeLists.txt file). Please make a build subdirectory. Feel free to "
                        "remove CMakeCache.txt and CMakeFiles.")
endif()

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(libs)
