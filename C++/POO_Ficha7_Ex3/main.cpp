#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Livro.h"
#include "Policial.h"
#include "FC.h"
#include "Biblio.h"

using namespace std;

int main(int argc, char** argv)
{
    Livro *l1 = new Livro("T1","A1","123");
    Policial *l2 = new Policial("T2","A2","51","D1",100);
    FC *l3 = new FC("T3","A3","11","Marte",2020,true);
    
    cout << *l1 << endl;
    cout << *l2 << endl;
    cout << *l3 << endl;
    
    Biblio b("Coimbra");
    
    b.addLivro(new Livro("A","B","11"));
    b.addLivro(new Policial("C","D","22","E",23));
    b.addLivro(new FC("X","Y","33","W",2100,true));
    //nao se pode repetir livro
    b.addLivro(new FC("X","Y","11","W",2100,true));
           
    cout << "B" << endl;
    cout << b << endl;
    
    Biblio c(b);
    
    cout << "C" << endl;
    cout << c << endl;
    
    //libertar memoria
    {
    delete l1;
    delete l2;
    delete l3;
    }
    
    return 0;
}