#pragma once

#include "INotation.hpp"
#include <string>

class ChessNotation : public INotation {
    public:
        ChessNotation(std::string stringNotation);

        bool IsValidLongNotation(){
            return isValidLongNotation;
        }

        bool IsValidShortNotation(){
            return isValidShortNotation;
        }

        bool IsValid() {
            return isValidLongNotation || isValidShortNotation;
        }

        std::string GetStringNotation(){
            return stringNotation;
        }

        bool IsPromotion(){
            return isPromotion;
        }

    private:
        std::string stringNotation;

        bool isPromotion = false;

        bool isValid = false;
        bool isValidLongNotation = false;
        bool isValidShortNotation = false;

        bool ValidationOfLongNotation();
        bool ValidationOfShortNotation();
};
