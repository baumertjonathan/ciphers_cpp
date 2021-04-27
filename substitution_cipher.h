#pragma once
#include <string>
#include <iostream>

class substitution_cipher
{
private:
	bool isValidKey(std::string key);
public:
	std::string encrypt(std::string text, std::string key);
	std::string decrypt(std::string text, std::string key);
};

