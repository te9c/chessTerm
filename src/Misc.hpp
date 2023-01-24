#pragma once

#include <string>

class Misc{
    public:
        static bool IsValidLongNotation(std::string notation);

        // Not implemented
        static bool IsValidShortNotation(std::string notation) {return false;}

        static bool IsValidNotation(std::string notation) {
            return IsValidLongNotation(notation) || IsValidShortNotation(notation);}
};
