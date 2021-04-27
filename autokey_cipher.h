#pragma once
#include <string>
#include <iostream>

class autokey_cipher
{
public:
	std::string encrypt(std::string text, std::string key);
	std::string decrypt(std::string text, std::string key);
};

