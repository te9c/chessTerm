project(tests)

include_directories(${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/src/)
set(CMAKE_CURRENT_BINARY_DIR )

#################### Google test installation
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
  )
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
####################

#################### Tests
add_executable(NotationTest NotationTest.cpp)

set_target_properties(NotationTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TestsBin")

target_link_libraries(NotationTest PRIVATE
    appLogic
    gtest_main)

add_test(NAME NotationTest COMMAND NotationTest)
