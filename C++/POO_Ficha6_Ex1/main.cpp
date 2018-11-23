#include "headers.h"
#include "Aquario.h"

int main()
{
    Peixe *p1 = new Peixe("Nemo", "Vermelho");
    Peixe *p2 = new Peixe("Dora");
    
    Aquario a("ISEC");
    
    a.addPeixe(p1);
    a.addPeixe(p2);
    
    cout << a << endl;
    
    cout << a.verificaPeixe(501) << endl;
    
    return 0;
}

