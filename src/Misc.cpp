#include "Misc.hpp"

#include <cstdlib>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cctype>
#include <array>

bool Misc::IsValidLongNotation(std::string notation){

    if (notation.size() != 4)
        return false;

    // transform to lowercase
    std::transform(notation.begin(), notation.end(), notation.begin(),
    [](unsigned char c){ return std::tolower(c); });

    if ((notation[0] - 'a' < 0 || notation[0] - 'a' > 7) || (notation[2] - 'a' < 0 || notation[2] - 'a' > 7))
        return false;
    if ((notation[1] < 49 || notation[1] > 56) || (notation[3] < 49 || notation[3] > 56))
        return false;

    return true;
}

bool Misc::IsValidFen(std::string FEN){
    std::array pieces = {'r','n','b','q','k','p','R','N','B','Q','K','P'};
    int counterPieces = 0; // should be 8 in each block
    int counterBlocks = 1; // should be 8 blocks
    int counterFields = 1; // should be 6 fields

    bool isMoveOrderInit = false;

    bool isCastlingBlank = false;
    int countK = 0;
    int countQ = 0;
    int countk = 0;
    int countq = 0;

    bool isEnPassantBlank = false;
    bool enPassantChar = false;
    bool enPassantNum = false;

    int halfMoveFieldStart = 0;

    int fullMoveFieldStart = 0;

    auto iter = FEN.begin();

    while (iter != FEN.end()){
        switch (counterFields){
            case 1:
                if (*iter == ' '){
                    counterFields++;
                    if(counterBlocks != 8 || counterPieces != 8)
                        return false;
                }
                else if (*iter == '/'){
                    counterBlocks++;
                    if(counterBlocks > 8 || counterPieces != 8)
                        return false;
                    counterPieces = 0;
                }
                else {
                    int num = std::atoi(&*iter);
                    if (num == 0){
                        if (std::find(std::begin(pieces),std::end(pieces),*iter) == std::end(pieces))
                            return false;
                        counterPieces++;
                    }else{
                        counterPieces += num;
                    }

                    if (counterPieces > 8)
                        return false;
                }
                iter++;
                break;
            case 2:
                if (*iter == ' '){
                    if (!isMoveOrderInit)
                        return false;
                    counterFields++;
                    iter++;
                }
                else if ((*iter == 'b' || *iter == 'w') && !isMoveOrderInit){
                    isMoveOrderInit = true;
                    iter++;
                }
                else
                    return false;
                break;
            case 3:
                if (*iter == ' '){
                    if (!isCastlingBlank && countq == 0 && countk == 0 && countQ == 0 && countK == 0)
                        return false;
                    counterFields++;
                    iter++;
                }
                else if (*iter == '-' && !isCastlingBlank && countq == 0 && countk == 0 && countK == 0 && countQ == 0){
                    isCastlingBlank = true;
                    iter++;
                }
                else if (*iter == 'K' && !isCastlingBlank){
                    countK++;
                    if (countK > 1)
                        return false;
                    iter++;
                }
                else if (*iter == 'Q' && !isCastlingBlank){
                    countQ++;
                    if (countQ > 1)
                        return false;
                    iter++;
                }
                else if (*iter == 'q' && !isCastlingBlank){
                    countq++;
                    if (countq > 1)
                        return false;
                    iter++;
                }
                else if (*iter == 'k' && !isCastlingBlank){
                    countk++;
                    if (countk > 1 )
                        return false;
                    iter++;
                }
                else {
                    return false;
                }
                break;
            case 4:
                if (*iter == ' '){
                    if (!isEnPassantBlank && !enPassantNum && !enPassantNum)
                        return false;
                    if (isEnPassantBlank || (enPassantNum && enPassantChar)){
                        counterFields++;
                        iter++;
                        halfMoveFieldStart = std::distance(FEN.begin(),iter);
                    }else {
                        return false;
                    }
                    break;
                }
                else if (*iter == '-' && !isEnPassantBlank && !enPassantNum && !enPassantChar){
                    isEnPassantBlank = true;
                    iter++;
                }
                else if (!enPassantChar && *iter - 'a' >= 0  && *iter -'a' <= 7){
                    enPassantChar = true;
                    iter++;
                }
                else if (!enPassantNum && (std::atoi(&*iter) == 3 || std::atoi(&*iter) == 6))
                {
                    enPassantNum = true;
                    iter++;
                }
                else
                    return false;
                break;
            case 5:
                if(*iter == ' '){
                    std::string halfMoveStr = FEN.substr(halfMoveFieldStart,std::distance(FEN.begin(),iter)-halfMoveFieldStart);

                    try{
                        if (std::stoi(halfMoveStr) == 0 && halfMoveStr.size() != 1)
                            return false;
                    }
                    catch (std::invalid_argument){
                        return false;
                    }
                    catch (std::out_of_range){
                        return false;
                    }

                    if (halfMoveStr[0] != '0' && halfMoveStr.size() == 1)
                        return false;
                    iter++;
                    fullMoveFieldStart = std::distance(FEN.begin(),iter);
                    counterFields++;
                }else
                    iter++;
                break;
            case 6:
                iter++;
                break;
        }
    }
    if (counterFields != 6)
        return false;
    try{
        if (std::stoi(FEN.substr(fullMoveFieldStart,FEN.size() - fullMoveFieldStart)) == '0')
            return false;
    }catch (std::invalid_argument){
        return false;
    }catch (std::out_of_range){
        return false;
    }

    return true;
}
