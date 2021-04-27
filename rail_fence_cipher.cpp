#include "rail_fence_cipher.h"
#include <string>
#include <iostream>
#include <vector>

std::string rail_fence_cipher::encrypt(std::string text, int rails)
{
	if (!validate(text, rails))
	{
		std::cout << "invalid text/rails";
		return "";
	}
	std::string result = "";
	bool direction = true; //true for ++ false for --
	int j = 0;
	std::vector<std::vector<char>> rail(rails, std::vector<char> (text.length(), '.'));
	// Fill the rail
	for (size_t i = 0; i < text.length(); i++)
	{
		rail[j][i] = text[i];
		if (direction)
			j++;
		else
			j--;
		if (j == rails-1)
			direction = false;
		if (j == 0)
			direction = true;
	}
	// Read the rail
	for (int i = 0; i < rails; i++)
	{
		for (size_t j = 0; j < text.length(); j++)
		{
			if (rail[i][j] != '.')
				result += rail[i][j];
		}
	}
	return result;
}

std::string rail_fence_cipher::decrypt(std::string text, int rails)
{
	if (!validate(text, rails))
	{
		std::cout << "invalid text/rails";
		return "";
	}
	std::string result = "";
	bool direction = true; 
	int j = 0;
	int k = 0;
	std::vector<std::vector<char>> rail(rails, std::vector<char>(text.length(), '.'));
	// Mark spaces on rail
	for (size_t i = 0; i < text.length(); i++)
	{
		rail[j][i] = '*';
		if (direction)
			j++;
		else
			j--;
		if (j == rails - 1)
			direction = false;
		if (j == 0)
			direction = true;
	}
	// fill horizontally
	for (int i = 0; i < rails; i++)
	{
		for (size_t j = 0; j < text.length(); j++)
		{
			if (rail[i][j] != '.')
			{
				rail[i][j] = text[k];
				k++;
			}	
		}
	}
	// Read the rail
	direction = true;
	j = 0;
	for (size_t i = 0; i < text.length(); i++)
	{
		result += rail[j][i];
		if (direction)
			j++;
		else
			j--;
		if (j == rails - 1)
			direction = false;
		if (j == 0)
			direction = true;
	}
	return result;
}

bool rail_fence_cipher::validate(std::string text, int rails)
{
	if (static_cast<int>(text.length()) <= rails)
		return false;
	else
		return true;
}

void rail_fence_cipher::printRail(std::vector<std::vector<char>> rail)
{
	for (int i = 0; i < rail.size(); i++)
	{
		for (int j = 0; j < rail[i].size(); j++)
		{
			std::cout << rail[i][j] << " ";
		}
		std::cout << std::endl;
	}
}