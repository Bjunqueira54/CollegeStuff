#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    string cmd, aux;
    vector<string> parsed_cmd;
    
    cin >> cmd;
    
    istringstream is;
    
    is.str(cmd);
    
    while(1)
    {
        is >> aux;
        
        if(aux == "")
            break;
        
        parsed_cmd.push_back(aux);
    }
    
    for(auto it: parsed_cmd)
        cout << it << endl;
    
    return 0;
}