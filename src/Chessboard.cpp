#include "Chessboard.hpp"

#include <string>
#include <vector>
#include <iostream>

const std::string startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

const std::string clearFEN = "8/8/8/8/8/8/8/8 w - - 0 1";

Chessboard::Chessboard() : Chessboard(std::string(clearFEN)){}

Chessboard::Chessboard(std::string FEN){
}
