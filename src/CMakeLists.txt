project(ChessApp)

set(CHESS_LOGIC_SOURCES
    boards/Board.hpp
    boards/Chessboard.cpp
    boards/Chessboard.hpp

    notations/Notation.hpp
    notations/ChessNotation.hpp
    notations/ChessNotation.cpp
    )

set(SCREEN_LOGIC_SOURCES
    Screen.cpp
    Screen.hpp
    )

set(CORE_SOURCES
    Session.cpp
    Session.hpp
    Misc.hpp
    Misc.cpp
    )

set(LOGIC_SOURCES
    ${CORE_SOURCES}
    ${CHESS_LOGIC_SOURCES}
    ${SCREEN_LOGIC_SOURCES})

add_library(appLogic STATIC ${LOGIC_SOURCES})

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE appLogic)
