#include "headers.h"
#include "Functions.h"

using namespace std;

void parseCmd(string cmd, const Language lang)
{
    string parse;
    istringstream is;
    
    is.str(cmd);
    
    while(is >> parse)
    {
        for(int i=0; i<lang.getCmdvec().size(); i++)
        {
            if(parse.compare(lang.getCmd(i)) == 0)
            {
                mvwaddstr(stdscr, 4, 0, lang.getLine(14));
                return;
            }
        }
        
        mvwaddstr(stdscr, 4, 0, "Command doesn't Exist");
        return;
    }
}

int getCenter(string a)
{
    int x;
    
    x = (80-strlen(a.c_str()))/2;
    
    return x;
}