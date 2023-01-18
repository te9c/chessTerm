project(ChessApp)

set(CHESS_LOGIC_SOURCES
    Chessboard.cpp
    Chessboard.hpp
    )

set(SCREEN_LOGIC_SOURCES
    Screen.cpp
    Screen.hpp
    )

set(CORE_SOURCES
    Session.cpp
    Session.hpp
    # tbd
    )

set(LOGIC_SOURCES
    ${CORE_SOURCES}
    ${CHESS_LOGIC_SOURCES}
    ${SCREEN_LOGIC_SOURCES})

add_library(appLogic STATIC ${LOGIC_SOURCES})

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE appLogic)
