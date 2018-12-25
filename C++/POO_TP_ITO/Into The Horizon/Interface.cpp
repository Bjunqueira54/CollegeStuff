#include "Interface.h"

Interface::Interface() {}

Interface::Interface(const Interface& orig) {}

void Interface::SetScreenSize(int lines, int columns)
{
    #ifdef __linux__

    std::ostringstream syscmd;
    syscmd << "\e[8;" << lines << ";" << columns << "t";
    std::cout << syscmd.str();

    #elif _WIN32

    #include "Consola.h"

    Consola::setScreenSize(lines, columns);

    #elif __unix__

    #include "Consola.h"

    Consola::setScreenSize(lines, columns);

    #endif
}

Interface::~Interface() {}