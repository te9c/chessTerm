#pragma once

#include <vector>
#include <string>

class Chessboard{
    private:
        std::vector<std::vector<int>> board;

        void IsValidMove(int Xfrom,int Yfrom,int Xto,int Yto);
    public:
        Chessboard(std::string FEN);

        Chessboard();

        bool Move(int Xfrom,int Yfrom, int Xto, int Yto); // true - Move valid; false Move isnt valid

        void ImportFEN(std::string FEN);

        bool IsCheckMate();

        std::string GetFEN();

        bool IsValidPosition();
}
