#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "headers.h"

class Language
{
    static vector <string> cmd;
    static vector <string> line;
    static vector <string> tutorial;
    
public:
    
    Language();
    Language(int lang);
    Language(const Language& orig);
    virtual ~Language();
};

#endif