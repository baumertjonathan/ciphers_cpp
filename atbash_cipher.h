#pragma once
#include <string>
#include <iostream>
#include <ctype.h>
#include <stdio.h>

class atbash_cipher
{
public: 
	std::string encrypt(std::string text);
	std::string decrypt(std::string text);
private:
	bool validate(std::string text);
};

