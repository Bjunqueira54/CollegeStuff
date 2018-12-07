#ifndef LIVRO_H
#define LIVRO_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Livro
{
    string titulo, autor, isbn;
    
public:
    
    Livro(string a, string b, string c);
    Livro(const Livro& orig);
    virtual ~Livro(); //obrigatorio ter destrutor virtual
    
    string getTitulo() const;
    string getAutor() const;
    string getIsbn() const;
    virtual string getInfo() const; //virtual - espera que as classes derivadas rescrevam o metodo
    
    bool operator==(const Livro &a);
    
    virtual Livro* clone(); //duplicacao polimorfica
};

ostream& operator<<(ostream &out, Livro &a);

#endif /* LIVRO_H */