#include "Settings.h"

Settings::Settings()
{
    startmoney = new int(0);
    pirateprob = new int(0);
    shipprice = new int(0);
    crewprice = new int(0);
    fishprice = new int(0);
    cargobuy = new int(0);
    cargosell = new int(0);
    harborcrew = new int(0);
    eventprob = new int(0);
    storm = new int(0);
    sirens = new int(0);
    calm = new int(0);
    riot = new int(0);
}

Settings::Settings(const Settings& orig) {}

Settings::Settings(const string filename)
{
    ifstream file;
    string input, parse;
    int l, c, n;
    file.open(filename, ios::in);
    
    do
    {
        getline(file, input);
    }
    while(input != "");
    
    while(!file.eof())
    {
	getline(file, input);
        istringstream is;
        is.str(input);
        
        is >> parse;
	
	if(parse == "lines" || parse == "linhas")
	{
	    is >> l;
	    
	    //Linhas e colunas não podem estar a 0. Solução temporaria
	   
	    if(l == 0)
		exit (EXIT_FAILURE);
	    else
		lines = new int(l);
	}
	else if(parse == "columns" || parse == "colunas")
	{
	    is >> c;
	    
	    if(c == 0)
		exit (EXIT_FAILURE);
	    else
		columns = new int(c);
	}
	else if(parse == "startmoney" || parse == "moedas")
	{
	    is >> n;
	    
	    if(n != 0)
		startmoney = new int(n);
	    else
		startmoney = new int(1000);
	}
	else if(parse == "probpirata" || parse == "pirateprob")
	{
	    is >> n;
	    
	    if(n != 0)
		pirateprob = new int(n);
	    else
		pirateprob = new int(20);
	}
	else if(parse == "preconavio" || parse == "shipprice")
	{
	    is >> n;
	    
	    if(n != 0)
		shipprice = new int(n);
	    else
		shipprice = new int(100);
	}
	else if(parse == "precosoldado" || parse == "crewprice")
	{
	    is >> n;
	    
	    if(n != 0)
		crewprice = new int(n);
	    else
		crewprice = new int(1);
	}
	else if(parse == "precovendpeixe" || parse == "fishprice")
	{
	    is >> n;
	    
	    if(n != 0)
		fishprice = new int(n);
	    else
		fishprice = new int(1);
	}
	else if(parse == "precocompmerc" || parse == "cargobuy")
	{
	    is >> n;
	    
	    if(n != 0)
		cargobuy = new int(n);
	    else
		cargobuy = new int(2);
	}
	else if(parse == "precovendmerc" || parse == "cargosell")
	{
	    is >> n;
	    
	    if(n != 0)
		cargosell = new int(n);
	    else
		cargosell = new int(3);
	}
	else if(parse == "soldadosporto" || parse == "harborcrew")
	{
	    is >> n;
	    
	    if(n != 0)
		harborcrew = new int(n);
	    else
		harborcrew = new int(100);
	}
	else if(parse == "probevento" || parse == "eventprob")
	{
	    is >> n;
	    
	    if(n != 0)
		eventprob = new int(n);
	    else
		eventprob = new int(30);
	}
	else if(parse == "probtempestade" || parse == "stormprob")
	{
	    is >> n;
	    
	    if(n != 0)
		storm = new int(n);
	    else
		storm = new int(30);
	}
	else if(parse == "probsereias" || parse == "sirenprob")
	{
	    is >> n;
	    
	    if(n != 0)
		sirens = new int(n);
	    else
		sirens = new int(30);
	}
	else if(parse == "probcalmaria" || parse == "calmprob")
	{
	    is >> n;
	    
	    if(n != 0)
		calm = new int(n);
	    else
		calm = new int(20);
	}
	else if(parse == "probmotim" || parse == "riotprob")
	{
	    is >> n;
	    
	    if(n != 0)
		riot = new int(n);
	    else
		riot = new int(20);
	}
	else
	{
	    map.push_back(input);
	    for(int i=1; i<lines; i++)
	    {
		getline(file, input);
		map.push_back(input);
	    }
	}
    }
}

Settings::~Settings()
{
    delete lines;
    delete columns;
    delete startmoney;
    delete pirateprob;
    delete shipprice;
    delete crewprice;
    delete fishprice;
    delete cargobuy;
    delete cargosell;
    delete harborcrew;
    delete eventprob;
    delete storm;
    delete sirens;
    delete calm;
    delete riot;
}