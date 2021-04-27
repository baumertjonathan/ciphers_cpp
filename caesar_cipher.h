#pragma once
#include <string>

class caesar_cipher
{
public:
	std::string encrypt(std::string text, int s);
	std::string decrypt(std::string text, int s);
};

