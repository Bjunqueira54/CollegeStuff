#include "Aviso.h"

using namespace std;

int main(int argc, char** argv)
{
    Prego p1(2, 4);
    Prego p2(5, 1);
    
    Aviso a1("Fechado", &p1);
    Aviso a2("Molhado", &p1);
    
    p1.MudaDeSitio(3, 10);
    a1.mudaDePrego(&p2);
    
    cout << a1.getInfo() << endl;
    
    return 0;
}

