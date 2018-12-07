#include "headers.h"
#include "Tarifario.h"
#include "Apressado.h"
#include "Cliente.h"

int main(int argc, char** argv)
{
    Cliente *a = new Cliente("Ana", 21270345, new Apressado);
    
    a->IniciaTreino(25);
    a->TerminaTreino(40);
    
    a->IniciaTreino(120);
    a->IniciaTreino(135);
    
    cout << a->pagar() << endl;
    
    return 0;
}

