#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    fstream testfile;
    testfile.open("example.mhw", fstream::out | fstream::in | fstream::app);
    if(testfile.is_open())
    {
        string phrase="";
        
        while(phrase != "exit")
        {
            getline(cin, phrase);
            if(phrase == "exit")
                break;
            
            testfile << phrase << endl;
        }
    }
    
    string rfile;
    testfile.seekg(fstream::beg);
    
    while(!testfile.eof())
    {
        getline(testfile, rfile);
        cout << rfile << endl;
    }
    
    testfile.close();
    return 0;
}

