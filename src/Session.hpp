#pragma once

#include "boards/IBoard.hpp"
#include <typeinfo>

class Session{
    public:
        ~Session(){
            delete board;
        }

        Session(IBoard board) {
            this->board = &board;
        }

        IBoard *GetBoard() {
            return board;
        }

    private:
        IBoard* board;
};
