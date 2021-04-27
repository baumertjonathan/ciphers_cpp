#include "affine_cipher.h"

std::string affine_cipher::encrypt(std::string text, int a, int b)
{
    if (!validate(text, a, b))
    {
        return "";
    }
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string result = "";
    for (size_t i{}; i < text.length(); i++)
    {
        int p = alphabet.find(tolower(text[i]));
        int c = (a * p + b) % 26;
        result += alphabet[c];
    }
    return result;
}

std::string affine_cipher::decrypt(std::string text, int a, int b)
{
    if (!validate(text, a, b))
    {
        return "";
    }
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string result = "";
    int a_inv = 0;
    int f = 0;
    //find a^-1 % 26
    for (int i = 0; i < 26; i++)
    {
        f = (a * i) % 26;
        if (f == 1)
            a_inv = i;
    }
    for (size_t i{}; i < text.length(); i++)
    {
        int c = alphabet.find(tolower(text[i]));
        int p = (int)(a_inv*(c - b)) % 26;
        result += alphabet[p];
    }
    return result;
}

bool affine_cipher::validate(std::string text, int a, int b)
{
    // validate a
    if (a < 1 || a > 26)
    {
        return false;
    }
    // validate b
    if (b < 1 || b > 26)
    {
        return false;
    }
    // check if is alpha
    for (size_t i{}; i < text.length(); i++)
    {
        if (!isalpha(text[i]))
            return false;
    }
    return true;
}
