#include "Misc.hpp"

#include <cstdlib>
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
}
