#include <gtest/gtest.h>
#include "Chessboard.hpp"

// this is garbage
TEST(ChessboardConstructor,testBoardWithValidInput){
    Chessboard b1;
    Chessboard b2("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    char** expb1 = new char*[8];
    char expb2[8][8] = {
        {'R','N','B','Q','K','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','q','k','b','n','r'},
    };

    for (int i = 0; i < 8; i++) {
        expb1[i] = new char[8];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            expb1[i][j] = ' ';
        }
    }

    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            EXPECT_EQ(b1.GetBoard()[i][j], expb1[i][j]) << "Arrays differ at index [" << i << "]" << "[" << j << "]";
        }
    }
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            EXPECT_EQ(b2.GetBoard()[i][j], expb2[i][j]) << "Arrays differ at index [" << i << "]" << "[" << j << "]";
        }
    }
}
