#ifndef CLASSDESENHO_H
#define CLASSDESENHO_H
#include "../ficha3_ex1/libs.h"
#include "../ficha3_ex3/classRetangulo.h"
#include "../ficha3_ex1/classPonto.h"

class Desenho
{
    string name;
    vector <Retangulo> v;
    
public:
    Desenho(string s): name(s) {}
    
    bool addR(Retangulo a)
    {
        v.push_back(a);
        return true;
    }
    
    int areaTotal()
    {
        int tot=0;
        
        for(int i=0; i<v.size(); i++)
        {
            tot += v[i].getArea();
        }
        return tot;
    }
    
    /* other areaTotal()
     * 
     * for(auto it = v.begin(); it < v.end(); it++)
     *      tot += it -> getArea();
     * 
     * for(auto x:v)
     *      tot += x.getArea();
     */
    
    string getAsString() const
    {
        ostringstream os;
        int n = 1;
        
        os << "Nome Desenho: " << name << endl;
        
        for(int i=0; i<v.size(); i++)
        {
            os << "Retangulo " << n << ": " << endl << v[i].getAsString() << endl;
            n++;
        }
        return os.str();
    }
    
    vector <Retangulo> getConjRet(Ponto a) // devolve todos os retangulos com cse = argumento
    {
        vector <Retangulo> x;
        int n=1;
        
        cout << "Retangulos com CSE em (" << a.getx() << "," << a.gety() << ")" << endl;
        for(int i=0; i<v.size(); i++)
        {
            if (v[i].getCanto().getx() == a.getx() && v[i].getCanto().gety() == a.gety())
            {
                x.push_back(v[i]);
                cout << "Retangulo " << n << endl << "  Altura: " << v[i].getalt() << endl << "  Largura: " << v[i].getlarg() << endl;
            }
            n++;
        }
        return x;      
    }
    
    void elimina(int lim)
    {
        /* dá erro pois avanca duas vezes quando apaga
        for(auto it=v.begin(); it<v.end(); i++)
            if(it->getArea() > lim)
                it = v.erase(it); // devolve o novo interador (!)
        */
        auto it = v.begin();
        
        while(it<v.end())
        {
            if(it->getArea() > lim) // como é auto, o compiler não sabe o tipo, dá um erro, mas compila
                it = v.erase(it);
            else
                it++;
        }
    }
};

#endif /* CLASSDESENHO_H */