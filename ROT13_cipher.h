#pragma once
#include <string>
#include <iostream>

class ROT13_cipher
{
public:
	std::string encrypt(std::string text);
	std::string decrypt(std::string text);
private:
	bool validate(std::string text);
};

