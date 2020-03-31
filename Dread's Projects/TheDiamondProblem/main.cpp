#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

/*the whole point of this project is to determine the behavior
 of C++ multiple inheritance problem, Aka. "The Diamond Problem"
 
 * Take the following diagram of classes:
 * 
 *      A
 *     /  \
 *    B    C
 *     \  /
 *      D
 * 
 * Where D is the Child (derived) class of B and C, and B and C are the child classes of A.
 * 
 * The question is: How does calling parent constructors would work?
 
 
 * With this project I'll attempt to fill in the variables of A with constructors called all the way from D,
 * by following both B and C to reach A.
 */

using namespace std;

class A
{
    string name;
    int number;
    char letter;
    float decimal;
    
public:
    A() {}
    
    //Constructor for the B class
    A(string n, char c): name(n), letter(c) {}
    
    //Constructor for the C class
    A(int n, float f): number(n), decimal(f) {}
    
    const string getInfo() const
    {
        ostringstream os;
        
        os << "name=" << this->name << " number=" << this->number << " letter=" << this->letter << " decimal=" << this->decimal;
        
        return os.str();
    }
    
    virtual ~A() {};
};

class B: public virtual A
{
public:
    B(): A("Base Class", 'G') {}
    
    virtual ~B() {}
};

class C: public virtual A
{
public:
    C(): A(54, 5.4) {}
    
    virtual ~C() {}
};

class D: public B, C
{
public:
    D(): B(), C() {}
    
    ~D(){}
};

int main(int argc, char** argv)
{
    D *d = new D();
    
    cout << d->getInfo();
    
    getchar();
    
    return 0;
}

