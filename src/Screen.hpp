#pragma once

#include "Session.hpp"

class Screen {
    public:
        Session GetActiveSession() {
            return activeSession;
        }

    private:
        Session activeSession;

};
