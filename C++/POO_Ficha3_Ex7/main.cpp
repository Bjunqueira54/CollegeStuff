#include "Conta.h"
#include "Banco.h"

using namespace std;

int main(int argc, char** argv)
{
    Pessoa p1("Ana Silva", 1234, 555);
    Pessoa p2("Joao Alves", 5779, 668);
    
    Conta a(&p1);
    
    a.VariarSaldo(100);
    
    Pessoa const *p = a.getTitular();
    
    Banco b1("CGD");
    
    b1.AddConta(Conta(&p1));
    b1.AddConta(Conta(&p2));
    
    b1.Deposita(100, 1234);
    
    cout << b1.getNomes() << endl;
    cout << b1.getSaldos() << endl;
    
    Conta const* c = b1.getConta(1234);
    
    b1.eliminaConta(1234);
    
    return 0;
}

