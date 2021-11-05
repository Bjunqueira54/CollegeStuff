#include <iostream>
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

	std::cout << "Building table. Please wait..." << std::endl;

	std::vector<std::vector<std::string>>* table = buildTableFromFile(iFile);

	std::cout << "Enable NoDrop? (0 to always drop items)" << std::endl;
	std::cout << "Input: ";

	int dropChance = 0;

	std::cin >> dropChance;

	std::cout << "Wait..." << std::endl;

	int COLUMN = 0;

	for (int i = 0; i < table->at(0).size(); i++)
	{
		if (std::strcmp(table->at(0).at(i).c_str(), "NoDrop") == 0)
		{
			COLUMN = i;
			break;
		}
	}

	for (int i = 1; i < table->size(); i++)	//start @1 because 0 is just headers
	{
		//I won't check for null fields this version
		/*if (
			(table->at(i).at(25) == "" && table->at(i).at(26) == "") ||
			(table->at(i).at(neutralRow) == "")
			)
			continue;*/

		//int NoDrop = std::stoi(table->at(i).at(COLUMN)); ----> I'll leave this here to remind me how retarded I am

		//NoDrop = dropChance;

		table->at(i).at(COLUMN) = std::to_string(dropChance);
	}

	std::cout << "Writting file..." << std::endl;

	std::ofstream oFile(fpath);

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

	return 0;
}