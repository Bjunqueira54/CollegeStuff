#ifndef MAIN_H
#define MAIN_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

#ifdef _WIN32

#include "Consola.h"

static void setScreenSize(int lines, int columns)
{
    Consola::setScreenSize(lines, columns);
}

#elif __linux__

static void setScreenSize(int lines, int columns)
{
    std::ostringstream syscmd;
    syscmd << "\e[8;" << lines << ";" << columns << "t";
    std::cout << syscmd.str();
}

#elif __unix__

#include "Consola.h"

static void setScreenSize(int lines, int columns)
{
    Consola::setScreenSize(lines, columns);
}
#endif


#endif /* MAIN_H */

