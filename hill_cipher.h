#pragma once
#include <string>
#include <iostream>
#include <vector>

class hill_cipher
{
public:
	std::string encrypt(std::string text, std::vector<std::vector<int>> key, char filler);
	std::string decrypt(std::string text, std::vector<std::vector<int>> key);
private:
	bool validatekey(std::vector<std::vector<int>> key);
	std::vector<int> matrixmultiplication(std::vector<std::vector<int>>, std::vector<int>);
};

