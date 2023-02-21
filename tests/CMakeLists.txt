project(tests)

include_directories(${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/src/)
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/TestsBin)

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

set(LIBS appLogic gtest_main gmock_main)

add_executable(MiscTest MiscTest.cpp)
add_executable(ChessboardTest ChessboardTest.cpp)
add_executable(NotationTest NotationTest.cpp)

set_target_properties(MiscTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TestsBin")
set_target_properties(ChessboardTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TestsBin")
set_target_properties(NotationTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/TestsBin")

target_link_libraries(MiscTest PRIVATE ${LIBS})
target_link_libraries(ChessboardTest PRIVATE ${LIBS})
target_link_libraries(NotationTest PRIVATE ${LIBS})

add_test(NAME MiscTest COMMAND MiscTest)
add_test(NAME ChessboardTest COMMAND ChessboardTest)
add_test(NAME NotationTest COMMAND NotationTest)
