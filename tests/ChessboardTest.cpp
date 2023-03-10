#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "boards/Chessboard.hpp"
#include <array>
#include <stdexcept>

//Note that when you initialize array you have to mirror your board

TEST(ChessboardConstructor,EmptyBoardInput){
    Chessboard cb;

    std::vector<std::vector<char>> expectedBoard = {{
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
    }};

    EXPECT_THAT(cb.GetBoardArray(), testing::ElementsAreArray(expectedBoard));
}

TEST(ChessboardConstructor,StartBoardInput){

    Chessboard cb("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    std::vector<std::vector<char>> expectedBoard = {{
        {'R','N','B','Q','K','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','q','k','b','n','r'},
    }};
    EXPECT_THAT(cb.GetBoardArray(), testing::ElementsAreArray(expectedBoard));
}

TEST(ChessboardGetFen,StaticInput){
    Chessboard cb1("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    Chessboard cb2;
    Chessboard cb3("r4r1k/1Rp3pp/1N1p4/n2Bpb2/3Pn3/2q4P/5PPN/R2Q2K1 w - - 0 30");
    Chessboard cb4("1rb2k1r/R2nqpbp/3p1np1/1p1P4/2p1PP2/2N1B3/1PQNB1PP/5RK1 b - d6 12 18");
    Chessboard cb5("1rb2k1r/R2nqpbp/3p1np1/1p1P4/2p1PP2/2N1B3/1PQNB1PP/5RK1 b - a1 12 18");

    EXPECT_EQ(cb1.GetFEN(),"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    EXPECT_EQ(cb2.GetFEN(),"8/8/8/8/8/8/8/8 w - - 0 1");
    EXPECT_EQ(cb3.GetFEN(),"r4r1k/1Rp3pp/1N1p4/n2Bpb2/3Pn3/2q4P/5PPN/R2Q2K1 w - - 0 30");
    EXPECT_EQ(cb4.GetFEN(),"1rb2k1r/R2nqpbp/3p1np1/1p1P4/2p1PP2/2N1B3/1PQNB1PP/5RK1 b - - 12 18");
    EXPECT_EQ(cb5.GetFEN(),"1rb2k1r/R2nqpbp/3p1np1/1p1P4/2p1PP2/2N1B3/1PQNB1PP/5RK1 b - - 12 18");
}

TEST(ChessboardMove,ExpectNullReference){
    Chessboard cb(Misc::startFEN);
    INotation *nullNotationPointer = new ChessNotation("a2b5");
    nullNotationPointer = NULL;
    EXPECT_THROW(cb.Move(nullNotationPointer), std::invalid_argument);
    delete nullNotationPointer;
}
