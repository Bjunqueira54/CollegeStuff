#include "headers.h"
#include "Agenda.h"

int main(int argc, char** argv)
{
    Agenda a;
    
    a.addContacto("Ana", 123456);
    a.addContacto("Luis", 654321);
    a.addContacto("Maria", 615243);
    
    cout << a << endl;
    
    cout << a.getTel("Luis") << endl;
    
    a.atualizaContacto("Maria", 435261);
    
    cout << a.getTel("Maria") << endl;
    
    a.eliminaContacto(123456);
    
    Agenda b(a);
    
    Agenda c;
    
    c.addContacto("Carlos",987654);
    
    c = a;
    
    cout << c << endl;;
    
    cout << a << endl;
    
    return 0;
}

