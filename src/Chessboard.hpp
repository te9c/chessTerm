#pragma once

#include <vector>
#include <string>
#include <array>

class Chessboard{
    private:
        std::array<std::array<char,8>,8> board;

        bool isCheckMate = false;

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

        Chessboard();

        std::array<std::array<char,8>,8> GetBoard() { return board; }

        bool Move(std::string notation); // true - Move valid; false Move isnt valid

        void ImportFEN(std::string FEN);

        bool GetIsCheckMate() { return isCheckMate; };

        std::string GetFEN();

        bool IsValidPosition();

};
