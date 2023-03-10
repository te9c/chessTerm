#pragma once

#include "../notations/INotation.hpp"
#include <vector>

class IBoard {
    public:
        virtual ~IBoard() {}

        virtual std::vector<std::vector<char>> GetBoardArray() = 0;

        virtual bool Move(INotation *notation) = 0;

        virtual bool IsValidPosition() = 0;

        virtual int GetMoveCounter() = 0;

        virtual void ImportFEN(std::string FEN) = 0;

        virtual std::string GetFEN() = 0;
};
