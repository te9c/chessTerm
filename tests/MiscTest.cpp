#include <gtest/gtest.h>
#include "Misc.hpp"


TEST(FenTest, HandlesValidInput){
    EXPECT_TRUE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
    EXPECT_TRUE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq d6 0 1"));

    EXPECT_TRUE(Misc::IsValidFen("8/8/8/8/8/8/8/8 w - - 0 1"));

    EXPECT_TRUE(Misc::IsValidFen("8/1Kkr1n2/Q3n1P1/2K1qN2/1n6/4B1N1/3B4/3K1Q2 w - - 0 1"));

    EXPECT_TRUE(Misc::IsValidFen("8/8/8/K1k5/8/r7/8/8 w - - 15 9"));
    EXPECT_TRUE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w Kk - 0 1"));

    EXPECT_TRUE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w Kk - 267 153"));
    EXPECT_TRUE(Misc::IsValidFen("rnbqkb1r/pppp1p1p/5n2/3P2p1/4p3/3BPN2/PPP2PPP/RNBQK2R w KQkq d1 0 6"));
}

TEST(FenTest,HandlesInvalidInput){

    EXPECT_FALSE(Misc::IsValidFen(""));
    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/ppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));

    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/ppp2pppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR l KQkq - 0 1"));

    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQRkq - 0 1"));
    EXPECT_FALSE(Misc::IsValidFen("/////// w KQkq - 0 5"));

    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR/RNBQKBNR w KQkq - 0 1"));
    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP w KQkq - 0 1"));

    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQ-q - 0 1"));
    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq d56 0 1"));
    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - d 1"));
    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq  - 0 1"));
    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 d"));

    EXPECT_FALSE(Misc::IsValidFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -d3 0 1"));
}
