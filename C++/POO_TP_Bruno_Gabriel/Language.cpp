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
        
        line.push_back("(Prima qualquer tecla para continuar)");    //0
        line.push_back("Bem vindo a Cid Martin's Pirates!");        //1
        line.push_back("1 - Novo Jogo");                            //2
        line.push_back("2 - Tutorial");                             //3
        line.push_back("3 - Creditos");                             //4
        line.push_back("4 - Sair do Jogo");                         //5
        line.push_back("Introduza o seu nome: ");                   //6
        line.push_back("Nome invalido!");                           //7
        line.push_back("Bem vindo ");                               //8
        line.push_back("Boa sorte marinheiro ");                    //9
        line.push_back("Turno ");                                   //10
        line.push_back("Comando: ");                                //11
        line.push_back("Comando não especificado");                 //12
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
        
        line.push_back("(Press any key to continue)");
        line.push_back("Welcome to High Sea Adventure!");
        line.push_back("1 - New Game");
        line.push_back("2 - Tutorial");
        line.push_back("3 - Credits");
        line.push_back("4 - Exit Game");
        line.push_back("Enter your name: ");
        line.push_back("Invalid name!");
        line.push_back("Welcome ");
        line.push_back("Good Luck sailor ");
        line.push_back("Turn ");
        line.push_back("Command: ");
        line.push_back("Command not specified");
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

//void Language::credPage(int n);