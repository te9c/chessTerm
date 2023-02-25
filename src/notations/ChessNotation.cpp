#include "ChessNotation.hpp"

#include "../Misc.hpp"
#include <algorithm>


ChessNotation::ChessNotation(std::string stringNotation)
{
    this->stringNotation = stringNotation;

    if (ValidationOfShortNotation())
    {
        isValid = true;
        isValidShortNotation = true;
    }
    if (ValidationOfLongNotation())
    {
        isValid = true;
        isValidLongNotation = true;
    }
}


// TODO: Implement short notations
bool ChessNotation::ValidationOfShortNotation(){
    return false;
}

bool ChessNotation::ValidationOfLongNotation()
{
    if (stringNotation.size() != 4  && stringNotation.size() != 5)
        return false;
    //
    // transform to lowercase
    std::transform(stringNotation.begin(), stringNotation.end(), stringNotation.begin(),
    [](unsigned char c){ return std::tolower(c); });

    if ((stringNotation[0] - 'a' < 0 || stringNotation[0] - 'a' > 7) || (stringNotation[2] - 'a' < 0 || stringNotation[2] - 'a' > 7))
        return false;
    if ((stringNotation[1] < 49 || stringNotation[1] > 56) || (stringNotation[3] < 49 || stringNotation[3] > 56))
        return false;

    if (stringNotation.size() == 5)
    {
        isPromotion = true;

        auto piece = std::find(Misc::pieces.begin(),Misc::pieces.end(),stringNotation[4]);
        if (piece == Misc::pieces.end())
            return false;
        if (*piece == 'k' || *piece == 'K')
            return false;
        if (*piece == 'p' || *piece == 'P')
            return false;
    }

    return true;
}
