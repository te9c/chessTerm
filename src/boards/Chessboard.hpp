#pragma once

#include "IBoard.hpp"
#include "../notations/ChessNotation.hpp"
#include "../Misc.hpp"

#include <vector>
#include <string>
#include <array>

class Chessboard : IBoard {
    private:
        std::vector<std::vector<char>> boardArray;

        int moveCounter;
        int fiftyRuleCounter;

        bool isWhiteToPlay;

        bool isPossibleCastleQ = false; // queen side white
        bool isPossibleCastleK = false; // king side white
        bool isPossibleCastleq = false; // queen side black
        bool isPossibleCastlek = false; // king side black

        std::string enPassantTarget = "";
    public:
        Chessboard(std::string FEN);
        Chessboard() : Chessboard(std::string(Misc::clearFEN)){};

        std::vector<std::vector<char>> GetBoardArray() { return boardArray; }

        bool Move(INotation &notation);

        bool IsValidPosition();

        int GetMoveCounter() {return moveCounter;};

        void ImportFEN(std::string FEN);

        bool IsCheckMate();

        std::string GetFEN();

};
