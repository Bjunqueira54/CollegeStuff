#ifndef STATES_H
#define STATES_H

#include "MainMenuState.h"

template<typename Base, typename T>
    inline bool instanceof(const T *ptr)
    {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }

#endif