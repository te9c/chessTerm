#pragma once

#include <string>
class INotation{
    public:
        ~INotation() {}

        virtual std::string GetStringNotation() = 0;

        virtual bool IsValid() = 0;
};
