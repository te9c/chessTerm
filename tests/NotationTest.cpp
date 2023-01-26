#include<gtest/gtest.h>
#include"Misc.hpp"

TEST(NotationTest, HandlesValidInput){
    EXPECT_TRUE(Misc::IsValidNotation("a2b6"));
}

TEST(NotationTest, HandlesValidBorderInput){
    EXPECT_TRUE(Misc::IsValidNotation("a1b8"));
    EXPECT_TRUE(Misc::IsValidNotation("h1a8"));
    EXPECT_TRUE(Misc::IsValidNotation("a5h4"));
}

TEST(NotationTest, HandlesInvalidInput){
    EXPECT_FALSE(Misc::IsValidNotation(""));
    EXPECT_FALSE(Misc::IsValidNotation("a4b65"));
    EXPECT_FALSE(Misc::IsValidNotation("a2 b5"));
    EXPECT_FALSE(Misc::IsValidNotation("a0b2"));
    EXPECT_FALSE(Misc::IsValidNotation("i2g5"));
}

TEST(NotationTest, HandlesUppercaseInput){
    GTEST_SKIP() << "Skipping uppercase input test. Not implemented yet";
    EXPECT_TRUE(Misc::IsValidNotation("A2B5"));
    EXPECT_FALSE(Misc::IsValidNotation("G6I4"));
    EXPECT_FALSE(Misc::IsValidNotation("H9A2"));
}
