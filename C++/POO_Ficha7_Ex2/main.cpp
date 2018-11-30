#include "Imovel.h"
#include "Apartamento.h"
#include "Loja.h"
#include "Imobiliaria.h"

ostream& operator<<(ostream& out, Imovel &a)
{
    out << a.getInfo() << endl;
    
    return out;
}

int main(int argc, char** argv)
{
    Loja a(100);
    
    Apartamento b(510, 2, 2);
    
    Imobiliaria Im("ERA");
    
    /*Im.addImovel(&a);
    Im.addImovel(&b);*/
    
    cout << a.getCodigo() << endl;
    
    cout << b.getAndar() << endl;
    
    cout << a << endl;
    
    cout << b << endl;
    
    //cout << Im << endl;
    //Im.eliminaImovel(2);
    
    return 0;
}