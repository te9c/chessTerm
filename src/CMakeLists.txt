# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)
 
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  # Important: Specify a GIT_TAG XXXXX here.
)
 
FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
 
# ------------------------------------------------------------------------------

configure_file (config.h.in config.h @ONLY)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

include_directories (${CMAKE_CURRENT_BINARY_DIR})

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(CHESS_LOGIC_SOURCES
    boards/IBoard.hpp
    boards/Chessboard.cpp
    boards/Chessboard.hpp

    notations/INotation.hpp
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

set(LIBRARIES
    appLogic
    ftxui::screen
    ftxui::dom
    ${Boost_LIBRARIES})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LIBRARIES})
