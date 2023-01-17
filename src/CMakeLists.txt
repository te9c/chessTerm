project(ChessApp)

set(CHESS_LOGIC_SOURCES
    chessboard.cpp
    chessboard.hpp)

set(SCREEN_LOGIC_SOURCES
    screen.cpp)

set(CORE_SOURCES
    # tbd
    )

set(LOGIC_SOURCES
    ${CORE_SOURCES}
    ${CHESS_LOGIC_SOURCES}
    ${SCREEN_LOGIC_SOURCES})

add_library(appLogic STATIC ${LOGIC_SOURCES})

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE appLogic)
