#include "Chessboard.hpp"
#include "Misc.cpp"

#include <string>
#include <vector>
#include <iostream>

const std::string startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

const std::string clearFEN = "8/8/8/8/8/8/8/8 w - - 0 1";

Chessboard::Chessboard() : Chessboard(std::string(clearFEN)){}

Chessboard::Chessboard(std::string FEN){
    Chessboard::board = std::vector<std::vector<char>>(8,std::vector<char>(8,'0')); // vector init

    ImportFEN(FEN);
}

void Chessboard::ImportFEN(std::string FEN){

}
