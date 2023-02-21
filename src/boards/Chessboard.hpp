#pragma once

#include "Board.hpp"
#include "../notations/ChessNotation.hpp"
#include "../Misc.hpp"

#include <vector>
#include <string>
#include <array>

class Chessboard : public Board {
    private:
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

        bool Move(Notation &notation);

        bool Move(ChessNotation &notation);

        bool IsValidPosition();

        void ImportFEN(std::string FEN);

        bool IsCheckMate();

        std::string GetFEN();

};
