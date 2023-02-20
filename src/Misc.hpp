#pragma once

#include <string>

class Misc{
    public:
        inline static const std::string startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

        inline static const std::string clearFEN = "8/8/8/8/8/8/8/8 w - - 0 1";

        static bool IsValidLongNotation(std::string notation);

        // Not implemented
        static bool IsValidShortNotation(std::string notation) {return false;}

        static bool IsValidNotation(std::string notation) {
            return IsValidLongNotation(notation) || IsValidShortNotation(notation);}

        static bool IsValidFen(std::string FEN);
};
