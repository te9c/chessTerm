#include "Chessboard.hpp"
#include "Misc.cpp"

#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

const std::string startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

const std::string clearFEN = "8/8/8/8/8/8/8/8 w - - 0 1";


Chessboard::Chessboard() : Chessboard(std::string(clearFEN)){}

Chessboard::Chessboard(std::string FEN){
    for (int i = 0; i < 8; i++)
        Chessboard::board[i] = new char[8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = ' ';
        }
    }

    ImportFEN(FEN);
}

void Chessboard::ImportFEN(std::string FEN){
    if (!Misc::IsValidFen(FEN))
        throw std::invalid_argument("FEN \"" + FEN + "\" is invalid");

    int row = 7;
    int col = 0;
    auto iter = FEN.begin();
    while (*iter != ' '){
        if (*iter == '/'){
            row--;
            col = 0;
        } else if (isdigit(*iter)){
            int skip = *iter - '0';
            col += skip;
        } else {
            Chessboard::board[row][col] = *iter;
            col++;
        }
        iter++;
    }

    iter++;
    Chessboard::isWhiteToPlay = *iter == 'w';
    iter += 2;

    while (*iter != ' '){
        if (*iter == 'K')
            Chessboard::isPossibleCastleK = true;
        if (*iter == 'Q')
            Chessboard::isPossibleCastleQ = true;
        if (*iter == 'k')
            Chessboard::isPossibleCastlek = true;
        if (*iter == 'q')
            Chessboard::isPossibleCastleq = true;
        iter++;
    }
    iter++;
    if (*iter != '-'){
        Chessboard::enPassantTarget = *iter + *(iter+1);
        iter += 3;
    }else
        iter += 2;

    Chessboard::fiftyRuleCounter = atoi(&*iter);
    iter += 2;
    Chessboard::moveCounter = atoi(&*iter);
    if (moveCounter == 0)
        moveCounter = 1;
}
