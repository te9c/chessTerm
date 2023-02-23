#include "Chessboard.hpp"
#include "../Misc.cpp"

#include <cctype>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <array>

Chessboard::Chessboard(std::string FEN){
    Chessboard::boardArray = std::vector<std::vector<char>>(8,std::vector<char>(8,' '));

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
            Chessboard::boardArray[row][col] = *iter;
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

        int row = std::atoi(&enPassantTarget[1]) - 1;
        int column = enPassantTarget[0] - 'a';

        if (row != 2 && row != 5)
            enPassantTarget = "";
        else{
            if (Chessboard::boardArray[row][column] == 'p'){
                if (column == 0){
                    if (Chessboard::boardArray[row][column++] != 'P')
                        enPassantTarget = "";
                }
                else if (column == 7){
                    if (Chessboard::boardArray[row][column--] != 'P')
                        enPassantTarget = "";
                }
                else {
                    if (Chessboard::boardArray[row][column++] != 'P' && Chessboard::boardArray[row][column--] != 'P')
                        enPassantTarget = "";
                }
            }else if (Chessboard::boardArray[row][column] == 'P'){
                if (column == 0){
                    if (Chessboard::boardArray[row][column++] != 'p')
                        enPassantTarget = "";
                }
                else if (column == 7){
                    if (Chessboard::boardArray[row][column--] != 'p')
                        enPassantTarget = "";
                }
                else {
                    if (Chessboard::boardArray[row][column++] != 'p' && Chessboard::boardArray[row][column--] != 'p')
                        enPassantTarget = "";
                }
            }else{
                enPassantTarget = "";
            }
        }
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
        for (auto y : boardArray[i]) {
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

bool Chessboard::IsValidPosition(){
    // if (Chessboard::IsCheckMate())
    //     return false;

    int whiteKingCounter = 0;
    int blackKingCounter = 0;

    for(auto x : boardArray){
        for(auto y : x){
            if (y == 'k')
                whiteKingCounter++;
            if (y == 'K')
                blackKingCounter++;
        }
    }
    if (whiteKingCounter != 1 || blackKingCounter != 1)
        return false;

    return true;
}

bool Chessboard::Move(INotation *notation){
    if (!notation)
        throw std::invalid_argument("NULL reference");
    ChessNotation *chessNotationCast = dynamic_cast<ChessNotation *>(notation);
    if (!chessNotationCast)
        throw std::invalid_argument(std::string(typeid(notation).name()) + " is not type ChessNotation");

    return Chessboard::Move(*chessNotationCast);
}

// TODO: implement Move function
bool Chessboard::Move(ChessNotation notation){
    return false;
}
