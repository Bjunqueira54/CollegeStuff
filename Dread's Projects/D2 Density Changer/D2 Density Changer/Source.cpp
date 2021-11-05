#include <cstdlib>
#include <iostream>
#include <string>

#include "D2TableFunctions.h"

int main(int argc, char** argv)
{
	std::cout << "Please write the file path: ";
	std::string fpath;
	std::getline(std::cin, fpath);
	std::ifstream iFile(fpath);

	if (!iFile)
	{
		std::cout << "Something went wrong!" << std::endl;
		return -1;
	}

	std::cout << "Wait..." << std::endl;

	std::vector<std::vector<std::string>>* table = buildTableFromFile(iFile);

	std::cout << "Density Multiplied by: ";
	int density;
	std::cin >> density;

	//Columns to edit at 25 & 26

	int neutralRow = 0;

	for (int i = 0; i < table->at(0).size(); i++)
	{
		if (std::strcmp(table->at(0).at(i).c_str(), "Level") == 0)
		{
			neutralRow = i;
			break;
		}
	}

	for (int i = 1; i < table->size(); i++)	//start @1 because 0 is just headers
	{
		if	(
				(table->at(i).at(25) == "" && table->at(i).at(26) == "") ||
				(table->at(i).at(neutralRow) == "")
			)
			continue;

		int minGrp = std::stoi(table->at(i).at(25));
		int maxGrp = std::stoi(table->at(i).at(26));

		minGrp *= density;
		maxGrp *= density;

		table->at(i).at(25) = std::to_string(minGrp);
		table->at(i).at(26) = std::to_string(maxGrp);
	}

	std::cout << "Wait..." << std::endl;

	std::string newfpath(fpath);

	for (int i = 0; i < 4; i++)
		newfpath.pop_back();

	newfpath.append("_");
	newfpath.append(std::to_string(density));
	newfpath.append(".txt");

	std::ofstream oFile(newfpath);

	for (int i = 0; i < table->size(); i++)
	{
		std::vector<std::string>& aux = table->at(i);

		for (int j = 0; j < aux.size(); j++)
		{
			oFile << aux.at(j);

			if (j == aux.size() - 1)
				oFile << '\n';
			else
				oFile << '\t';
		}
	}

	std::cout << "Wait...";
}