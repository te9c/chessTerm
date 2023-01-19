#pragma once

#include <vector>
#include <string>

class Chessboard{
    private:
        std::vector<std::vector<char>> board;

        void IsValidMove(std::string notation);
    public:
        Chessboard(std::string FEN);

        Chessboard();

        std::vector<std::vector<char>> GetBoard(){ return board; }

        bool Move(std::string notation); // true - Move valid; false Move isnt valid

        void ImportFEN(std::string FEN);

        bool IsCheckMate();

        std::string GetFEN();

        bool IsValidPosition();

};
