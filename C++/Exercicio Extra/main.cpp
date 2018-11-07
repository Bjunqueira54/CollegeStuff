#include "Movimentos.h"

int main(int argc, char** argv)
{
    Movimentos p1("Artur Almeida", 150);
    p1 = p1 + 50;
    p1 = p1 - 25;
    p1 += 40;
    p1 - 50;
    
    cout << p1 << endl;
    
    return 0;
}

