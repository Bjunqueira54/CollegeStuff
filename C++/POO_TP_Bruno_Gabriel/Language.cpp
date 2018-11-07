#include "Language.h"

vector <string> Language::cmd;
vector <string> Language::line;
vector <string> Language::tutorial;

Language::Language(int lang)
{
    if(lang == 1)
    {
        cmd.push_back("config");
        cmd.push_back("exec");
        cmd.push_back("prox");
        cmd.push_back("compranav");
        cmd.push_back("vendenav");
        cmd.push_back("lista");
        cmd.push_back("compra");
        cmd.push_back("move");
        cmd.push_back("auto");
        cmd.push_back("stop");
        cmd.push_back("pirata");
        cmd.push_back("evpos");
        cmd.push_back("evnav");
        cmd.push_back("moedas");
        cmd.push_back("vaipara");
        cmd.push_back("comprasold");
        cmd.push_back("saveg");
        cmd.push_back("loadg");
        cmd.push_back("delg");
        cmd.push_back("sair");
        
        line.push_back("(Carrega em qualquer tecla para continuar...");
    }
    else if(lang == 2)
    {
        cmd.push_back("config");
        cmd.push_back("exec");
        cmd.push_back("next");
        cmd.push_back("buyship");
        cmd.push_back("sellship");
        cmd.push_back("list");
        cmd.push_back("buy");
        cmd.push_back("move");
        cmd.push_back("auto");
        cmd.push_back("stop");
        cmd.push_back("pirate");
        cmd.push_back("evpos");
        cmd.push_back("evship");
        cmd.push_back("coins");
        cmd.push_back("goto");
        cmd.push_back("buycrew");
        cmd.push_back("saveg");
        cmd.push_back("loadg");
        cmd.push_back("delg");
        cmd.push_back("exit");
        
        line.push_back("(Press any key to continue...");
    }
}

vector <string>& Language::getLine()
{
    return line;
}

vector <string>& Language::getCmd()
{
    return cmd;
}

void Language::tutPage(int n)
{
    
}