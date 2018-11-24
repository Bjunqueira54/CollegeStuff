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
    
    vector <string> getLinevec() const;  //Atrevam-se a brincar com isto e depois virem perguntar porque é que
    vector <string> getCmdvec() const;   //isto não funciona, dou cabo de vocês. Assinado: Bruno
    static const char* getCmd(int i);
    static const char* getLine(int i);
    static void tutPage();
    static void credPage();
};

#endif