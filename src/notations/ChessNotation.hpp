#pragma once

#include "INotation.hpp"
#include <string>

class ChessNotation : INotation {
    public:
        ChessNotation(std::string stringNotation) {
            this->stringNotation = stringNotation;};

        std::string GetStringRepresentation() {return stringNotation;};

        bool IsValidLongNotation();

        bool IsValidShortNotation();

        bool IsValid() {
            return IsValidLongNotation() || IsValidShortNotation();};
    private:
        std::string stringNotation;
};
