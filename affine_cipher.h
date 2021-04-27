#pragma once
#include <string>
#include <cmath>
#include <iostream>

class affine_cipher
{
public:
	std::string encrypt(std::string text, int a, int b);
	std::string decrypt(std::string text, int a, int b);
private:
	bool validate(std::string text, int a, int b);
};

