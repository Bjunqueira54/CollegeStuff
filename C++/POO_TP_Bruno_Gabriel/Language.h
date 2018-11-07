#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "headers.h"

class Language
{
    static vector <string> cmd;
    static vector <string> line;
    static vector <string> tutorial;
    
public:
    
    Language(string lang);
    
    static string getLine(int n);
    static string getCmd(int n);
    static void tutPage(int n);
};

#endif /* LANGUAGE_H */

