#pragma once

#include "../notations/Notation.hpp"
#include <vector>

class Board {
    public:
        virtual std::vector<std::vector<char>> GetBoardArray() {
            return boardArray;
        }

        virtual bool Move(Notation &notation) {
            return false;
        }

        virtual bool IsValidPosition() {
            return false;
        }

        virtual int GetMoveCounter() {
            return moveCounter;
        }

    protected:
        std::vector<std::vector<char>> boardArray;

        int moveCounter = 0;
};
