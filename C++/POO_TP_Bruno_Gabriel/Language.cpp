#include "Language.h"

vector <string> Language::cmd;
vector <string> Language::line;
vector <string> Language::tutorial;

Language::Language(int lang)
{
    if(lang == 1)
    {
        cmd[0] = "config";
        cmd[1] = "exec";
        cmd[2] = "prox";
        cmd[3] = "compranav";
        cmd[4] = "vendenav";
        cmd[5] = "lista";
        cmd[6] = "compra";
        cmd[7] = "move";
        cmd[8] = "auto";
        cmd[9] = "stop";
        cmd[10] = "pirata";
        cmd[11] = "evpos";
        cmd[12] = "evnav";
        cmd[13] = "moedas";
        cmd[14] = "vaipara";
        cmd[15] = "comprasold";
        cmd[16] = "saveg";
        cmd[17] = "loadg";
        cmd[18] = "delg";
        cmd[19] = "sair";
    }
    else if(lang == 2)
    {
        cmd[0] = "config";
        cmd[1] = "exec";
        cmd[2] = "next";
        cmd[3] = "buyship";
        cmd[4] = "sellship";
        cmd[5] = "list";
        cmd[6] = "buy";
        cmd[7] = "move";
        cmd[8] = "auto";
        cmd[9] = "stop";
        cmd[10] = "pirate";
        cmd[11] = "evpos";
        cmd[12] = "evship";
        cmd[13] = "coins";
        cmd[14] = "goto";
        cmd[15] = "buysoldier";
        cmd[16] = "saveg";
        cmd[17] = "loadg";
        cmd[18] = "delg";
        cmd[19] = "exit";
    }
}

string Language::getLine(int n)
{
    ostringstream gline;
    gline << line[n];
    return gline.str();
}

string Language::getCmd(int n)
{
    ostringstream gcmd;
    gcmd << cmd[n];
    return gcmd.str();
}

void Language::tutPage(int n)
{
    
}