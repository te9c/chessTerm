#pragma once

#include "Notation.hpp"
#include <string>

class ChessNotation : public Notation {
    public:
        ChessNotation(std::string stringNotation) : Notation(stringNotation){};

        bool IsValidLongNotation();

        bool IsValidShortNotation();

        bool IsValid() {
            return IsValidLongNotation() || IsValidShortNotation();};
};
