#include "MSG.h"

using namespace std;

void f1(MSG *a)
{
    delete a;
}

MSG *f2()
{
    return new MSG("F2");
}

int main(int argc, char** argv)
{
    MSG a("Local");
    MSG *b = new MSG("Dinamica");
    
    f1(b);
    
    MSG *c = f2();
    delete c;
    
    MSG *array = new MSG[3]{"Posicao1", "Posicao2", "Posicao3"};
    
    delete []array;
    
    return 0;
}

