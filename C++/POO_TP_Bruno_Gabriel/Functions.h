#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Language.h"

//Protótipos de funções

void drawUI(int nL, int nC); //Do not use. Pending nCurses implementation

void parseCmd(string cmd, const Language lang);

int getCenter(const char* a);

int getCenter(string a);


#endif /* FUNCTIONS_H */

