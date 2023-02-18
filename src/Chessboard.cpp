#include "Chessboard.hpp"
#include "Misc.cpp"

#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <array>

const std::string startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

const std::string clearFEN = "8/8/8/8/8/8/8/8 w - - 0 1";


Chessboard::Chessboard() : Chessboard(std::string(clearFEN)){}

Chessboard::Chessboard(std::string FEN){
    std::array<char,8> emptyArr;
    emptyArr.fill(' ');

    Chessboard::board.fill(emptyArr);

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
        Chessboard::enPassantTarget = std::string({*iter,*(iter+1)});
        iter += 3;
    }else
        iter += 2;

    Chessboard::fiftyRuleCounter = atoi(&*iter);
    iter += 2;
    Chessboard::moveCounter = atoi(&*iter);
    if (moveCounter == 0)
        moveCounter = 1;
}

std::string Chessboard::GetFEN(){
    std::string FEN;

    for (int i = 7; i >= 0; i--) {
        int counter = 0;
        for (auto y : board[i]) {
            if (y == ' ')
            {
                counter++;
            }
            else
            {
                if (counter != 0)
                    FEN += std::to_string(counter);
                counter = 0;
                FEN += y;
            }
        }
        if (counter != 0)
            FEN += std::to_string(counter);
        FEN += '/';
    }
    FEN.pop_back();

    FEN += ' ';
    if (isWhiteToPlay)
        FEN += 'w';
    else
        FEN += 'b';

    FEN += ' ';
    if (isPossibleCastleK)
        FEN += 'K';
    if (isPossibleCastleQ)
        FEN += 'Q';
    if (isPossibleCastlek)
        FEN += 'k';
    if (isPossibleCastleq)
        FEN += 'q';

    if (FEN[FEN.size()-1] == ' ')
        FEN += '-';

    FEN += ' ';
    if (enPassantTarget != "")
        FEN += enPassantTarget;
    else
        FEN += '-';

    FEN += ' ';
    FEN += std::to_string(fiftyRuleCounter);
    FEN += ' ';
    FEN += std::to_string(moveCounter);

    return FEN;
}
