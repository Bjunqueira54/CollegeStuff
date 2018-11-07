#include "../ficha3_ex1/libs.h"
#include "classDesenho.h"

int main(int argc, char** argv) 
{
    Desenho d("Folha");
    d.addR(Retangulo(Ponto(2,3),4,5));
    d.addR(Retangulo(Ponto(1,1),3,2));
    
    cout << "Area Total: " << d.areaTotal() << endl;
    cout << d.getAsString() << endl;
    auto x = d.getConjRet(Ponto(1,1));
    
    d.elimina(15);
    cout << d.getAsString() << endl;
    
    return 0;
}