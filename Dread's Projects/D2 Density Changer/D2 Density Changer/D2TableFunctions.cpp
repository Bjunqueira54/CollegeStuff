#include "D2TableFunctions.h"
#include "Parser.h"

std::vector<std::vector<std::string>>* buildTableFromFile(std::ifstream& f)
{
	std::vector<std::vector<std::string>>* vec = new std::vector<std::vector<std::string>>();

	int lastSize = 0;

	while (!f.eof())
	{
		std::vector<std::string> _auxVec;
		std::string line;
		std::getline(f, line);
		int newSize = 0;
		char** parsedLine = stringParser(line.c_str(), '\t');

		for (int i = 0; parsedLine[i] != NULL; i++)
		{
			_auxVec.push_back(parsedLine[i]);
			newSize = i;
		}

		if (lastSize == 0)
			lastSize = newSize;

		if (newSize < lastSize) //they should both be 255
			continue;

		vec->push_back(_auxVec);
	}

	return vec;
}