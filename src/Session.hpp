#pragma once

#include "boards/Board.hpp"

class Session{
    public:
        Session(Board board) {
            this->board = board;
        }

        Board GetBoard() {
            return board;
        }

    private:
        Board board;
};
