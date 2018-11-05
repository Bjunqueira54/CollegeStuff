#include "headers.h"
#include "Functions.h"

using namespace std;

void drawMainMenu()
{
    Consola::gotoxy(0,0);   //Começa no canto superior esquerdo da consola
    
    for(int y=0; y<20; y++)    //Ciclo para 20  linhas
    {
        for(int x=0; x<50; x++)    //Ciclo para 50 caracteres
        {
            if(y==0 || y == 20) //Se for a 1º ou a ultima linha
                if(x==50)
                    cout << '*' << endl;
                else
                    cout << '*';
            
        }
    }
}