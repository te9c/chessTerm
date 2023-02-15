#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Chessboard.hpp"
#include <array>

//Note that when you initialize array you have to mirror your board

TEST(ChessboardConstructor,EmptyBoardInput){
    Chessboard cb;

    std::array<std::array<char,8>,8> expectedBoard = {{
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
    }};

    EXPECT_THAT(cb.GetBoard(), testing::ElementsAreArray(expectedBoard));
}

TEST(ChessboardConstructor,StartBoardInput){

    Chessboard cb("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    std::array<std::array<char,8>,8> expectedBoard = {{
        {'R','N','B','Q','K','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','q','k','b','n','r'},
    }};
    EXPECT_THAT(cb.GetBoard(), testing::ElementsAreArray(expectedBoard));
}
