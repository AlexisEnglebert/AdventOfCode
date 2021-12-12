#include "SonarSweep.h"

void SonarSweep::resolve()
{
	std::ifstream stream("src/2021/01/input.txt"); 
	std::string line;
	int* data = new int[10000]; // Create new array on the Heap
	int previousSum = 0;
	int resultp1 = 0, resultp2 = 0;
	int nLines = 0;


	memset(data, 0, 10000);
	for (int i = 0; std::getline(stream, line); i++) { data[i] = std::stoi(line); nLines++; } //Read all lines from the file and convert lines to int
	for (int i = 1; i < nLines; i++)  //Resolution of Part 1 and 2 
	{
		int sum = 0;	
		if (i + 3 <= nLines) {for (int j = 0; j < 3; j++){sum += data[i + j];}resultp2 += sum > previousSum ? 1 : 0;}
		resultp1 += data[i] > data[i - 1] ? 1 : 0;
		previousSum = sum;
	}


	std::cout << resultp1 << std::endl;
	std::cout << resultp2 << std::endl;
	delete[] data;
} 
