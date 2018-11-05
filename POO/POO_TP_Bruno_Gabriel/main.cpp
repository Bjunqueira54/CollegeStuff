#include "headers.h"
#include "Functions.h"
#include "Player.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Welcome to Sid Meyer's Pirates! Wannabe" << endl;
    
    string name;
    cout << "Enter your name: ";
    cin >> name;
    
    int turno=0;
    
    Player player(name);
    
    while(1)
    {
        
        turno++;
    }
    return 0;
}

