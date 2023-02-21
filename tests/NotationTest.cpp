#include <gtest/gtest.h>
#include "notations/ChessNotation.hpp"

TEST(ValidationTest, LongNotationValidInput){
    EXPECT_TRUE(ChessNotation("a2b6").IsValidLongNotation());

    EXPECT_TRUE(ChessNotation("d7d8q").IsValidLongNotation());

    EXPECT_TRUE(ChessNotation("a2b7N").IsValidLongNotation());

    EXPECT_TRUE(ChessNotation("f2f1b").IsValidLongNotation());

    EXPECT_TRUE(ChessNotation("a1b8").IsValidLongNotation());
}

TEST(ValidationTest, LongNotationInvalidInput){
    EXPECT_FALSE(ChessNotation("").IsValidLongNotation());
    EXPECT_FALSE(ChessNotation("a4b65").IsValidLongNotation());
    EXPECT_FALSE(ChessNotation("a2 b5").IsValidLongNotation());
    EXPECT_FALSE(ChessNotation("a0b2").IsValidLongNotation());
    EXPECT_FALSE(ChessNotation("i2g5").IsValidLongNotation());

    EXPECT_FALSE(ChessNotation("a7a8k").IsValidLongNotation());
    EXPECT_FALSE(ChessNotation("e3g4P").IsValidLongNotation());
}

TEST(ValidationTest, LongNotationUppercaseInput){
    EXPECT_TRUE(ChessNotation("A2B5").IsValidLongNotation());
    EXPECT_FALSE(ChessNotation("G6I4").IsValidLongNotation());
    EXPECT_FALSE(ChessNotation("H9A2").IsValidLongNotation());
}
