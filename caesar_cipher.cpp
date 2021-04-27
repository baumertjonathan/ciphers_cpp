#include "caesar_cipher.h"
#include <iostream>
#include <string>

std::string caesar_cipher::encrypt(std::string text, int s)
{
    std::string result = "";
    for (size_t i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }
    return result;
}

std::string caesar_cipher::decrypt(std::string text, int s)
{
    std::string result = "";
    s = -s;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }
    return result;
}


