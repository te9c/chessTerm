#pragma once

#include <string>
class INotation{
    public:
        virtual ~INotation() {}

        virtual std::string GetStringRepresentation() = 0;

        virtual bool IsValid() = 0;
};
