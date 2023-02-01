#pragma once

#include <vector>
#include <string>

class Chessboard{
    private:
        char** board = new char*[8];

        int moveCounter;
        int fiftyRuleCounter;

        bool isWhiteToPlay;

        bool isPossibleCastleQ; // queen side white
        bool isPossibleCastleK; // king side white
        bool isPossibleCastleq; // queen side black
        bool isPossibleCastlek; // king side black

        std::string enPassantTarget;

        void IsValidMove(std::string notation);
    public:
        Chessboard(std::string FEN);

        Chessboard();

        char** GetBoard(){ return board; }

        bool Move(std::string notation); // true - Move valid; false Move isnt valid

        void ImportFEN(std::string FEN);

        bool IsCheckMate();

        std::string GetFEN();

        bool IsValidPosition();

};
