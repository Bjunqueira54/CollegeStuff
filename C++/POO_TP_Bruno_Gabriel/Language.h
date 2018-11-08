#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "headers.h"

class Language
{
    static vector <string> cmd;
    static vector <string> line;
    static vector <string> tutorial;
    static vector <string> credits;
    
public:
    
    Language(int lang);
    
    //static vector <string>& getLine();
    //static vector <string>& getCmd();
    static const char* getCmd(int i);
    static const char* getLine(int i);
    static void tutPage(int n);
    static void credPage(int n);
};

#endif /* LANGUAGE_H */

