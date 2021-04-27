#include "substitution_cipher.h"
#include <iostream>
#include <string>

std::string substitution_cipher::encrypt(std::string text, std::string key)
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string output = ""; 
	if (isValidKey(key))
	{
		for (size_t i{}; i < text.length(); i++)
		{
			int oldCharIndex = alphabet.find(tolower(text[i]));
			if (oldCharIndex >= 0)
				output += isupper(text[i]) ? toupper(key[oldCharIndex]) : key[oldCharIndex];
			else
				output += text[i];
		}
		return output;
		
	}
	else
		std::cout << "Invalid Key" << std::endl;
		return "";
}

std::string substitution_cipher::decrypt(std::string text, std::string key)
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string output = "";
	if (isValidKey(key))
	{
		for (size_t i{}; i < text.length(); i++)
		{
			int index = key.find(tolower(text[i]));
			if (index >= 0)
				output += isupper(text[i]) ? toupper(alphabet[index]) : alphabet[index];
			else
				output += text[i];
		}
		return output;
	}
	else
		std::cout << "Invalid Key" << std::endl;
		return "";
}

bool substitution_cipher::isValidKey(std::string key)
{
	// is 26 letters
	if (key.length() != 26)
	{
		return false;
	}
	// check for repeats

	for (size_t i{}; i < key.length(); i++)
	{
		for (size_t j{}; j < key.length(); j++)
		{
			if ((key[i] == key[j]) && (i != j)) {
				return false;
			}
		}

	}
	
	return true;
}