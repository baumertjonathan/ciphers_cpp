#pragma once
#include <string>
#include <vector>

class rail_fence_cipher
{
public:
	std::string encrypt(std::string text, int rails);
	std::string decrypt(std::string text, int rails);
private:
	bool validate(std::string, int rails);
	void printRail(std::vector<std::vector<char>> rail);
};

