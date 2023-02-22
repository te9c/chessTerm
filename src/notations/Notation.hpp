#pragma once

#include <string>
class Notation{
    public:
        Notation(std::string stringNotation) {
            this->stringNotation = stringNotation;
        }

        virtual std::string GetStringNotation() {
            return stringNotation;
        }

        virtual bool IsValid() {
            return false;
        }

    protected:
        std::string stringNotation = "";
};
