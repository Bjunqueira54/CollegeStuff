#include "Language.h"

vector <string> Language::cmd;
vector <string> Language::line;
vector <string> Language::tutorial;

Language::Language(int lang)
{
    if(lang == 1)
    {
        cmd.push_back("config");    //0
        cmd.push_back("exec");      //1
        cmd.push_back("prox");      //2
        cmd.push_back("compranav"); //3
        cmd.push_back("vendenav");  //4
        cmd.push_back("lista");     //5
        cmd.push_back("compra");    //6
        cmd.push_back("move");      //7
        cmd.push_back("auto");      //8
        cmd.push_back("stop");      //9
        cmd.push_back("pirata");    //10
        cmd.push_back("evpos");     //11
        cmd.push_back("evnav");     //12
        cmd.push_back("moedas");    //13
        cmd.push_back("vaipara");   //14
        cmd.push_back("comprasold");//15
        cmd.push_back("saveg");     //16
        cmd.push_back("loadg");     //17
        cmd.push_back("delg");      //18
        cmd.push_back("sair");      //19
        
        line.push_back("(Prima qualquer tecla para continuar)");
        line.push_back("Bem vindo a Cid Martin's Pirates!");
        line.push_back("1 - Novo Jogo");
        line.push_back("2 - Tutorial");
        line.push_back("3 - Creditos");
        line.push_back("4 - Sair do Jogo");
        line.push_back("Introduza o seu nome: ");
        line.push_back("Bem vindo ");
        line.push_back("Boa sorte e diverte-te!");
        line.push_back("Comando: ");
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
        
        line.push_back("(Press any key to continue");
        line.push_back("Welcome to High Sea Adventure!");
        line.push_back("1 - New Game");
        line.push_back("2 - Tutorial");
        line.push_back("3 - Credits");
        line.push_back("4 - Exit Game");
        line.push_back("Enter your name: ");
        line.push_back("Welcome ");
        line.push_back("Good Luck and Have Fun!");
        line.push_back("Command: ");
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

void Language::credPage(int n);