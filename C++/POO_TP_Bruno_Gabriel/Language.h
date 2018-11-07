#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "headers.h"

class Language
{
    vector <string> cmd;
    vector <string> line;
    vector <string> tutorial;
    
public:
    
    Language(){}
    
    string getLine();
    string getCmg();
    void tutPage();
};

#endif /* LANGUAGE_H */

