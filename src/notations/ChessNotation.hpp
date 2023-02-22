#pragma once

#include "INotation.hpp"
#include <string>

class ChessNotation : public INotation {
    public:
        ChessNotation(std::string stringNotation){
            this->stringNotation = stringNotation;
        };

        bool IsValidLongNotation();

        bool IsValidShortNotation();

        bool IsValid() {
            return IsValidLongNotation() || IsValidShortNotation();
        }

        std::string GetStringNotation(){
            return stringNotation;
        }

    private:
        std::string stringNotation;
};
