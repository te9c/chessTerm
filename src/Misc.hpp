#pragma once

#include <string>

class Misc{
    public:
        static bool IsValidLongNotation(std::string notation);

        static bool IsValidShortNotation(std::string notation);

        static bool IsValidNotation(std::string notation) {
            return IsValidLongNotation(notation) || IsValidShortNotation(notation);}
};
