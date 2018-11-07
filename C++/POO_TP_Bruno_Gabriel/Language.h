#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "headers.h"

class Language
{
    static vector <string> cmd;
    static vector <string> line;
    static vector <string> tutorial;
    
public:
    
    Language(int lang);
    
    static vector <string>& getLine();
    static vector <string>& getCmd();
    static void tutPage(int n);
};

#endif /* LANGUAGE_H */

