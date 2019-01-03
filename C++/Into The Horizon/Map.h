#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Harbor.h"
#include "Ocean.h"

class Map
{
    vector <Harbor*> harbors;
    vector <Ocean*> ocean;
    const int height, width;
    
public:

    Map(vector<string> vmap);
    
	//Returns a string with the format "Y X".
	const string getHarborCoord(int i) const { return harbors[i]->getCoord(); }
	//Returns a string with the format "Y X".
	const string getOceanCoord(int i) const { return ocean[i]->getCoord(); }
	//Return a string in the format of "HEIGHT WIDTH".
    const string getDim() const;
	const char getHarborID(int i) const { return harbors[i]->getID(); }
	const bool harborIsFriendly(int i) const { return harbors[i]->isFriendly(); }
    const int getTotalHarborTiles() const { return harbors.size(); }
	const int getOceanFish(int i) const { return ocean[i]->getFish(); }
    const int getTotalOceanTiles() const { return ocean.size(); }
	
	void OceanTurnUpdate();
	void OceanFished(string Coord);

    Harbor* getHarbor(int i) const { return harbors[i]; }
    
    virtual ~Map();
};

#endif