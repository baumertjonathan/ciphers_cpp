#include "atbash_cipher.h"

std::string atbash_cipher::encrypt(std::string text)
{
    if (!validate(text))
        return "";
    std::string substitution = "zyxwvutsrqponmlkjihgfedcba";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string output = "";
    for (size_t i{}; i < text.length(); i++)
    {
        
        int oldCharIndex = alphabet.find(tolower(text[i]));

        if (oldCharIndex >= 0)
            output += isupper(text[i]) ? toupper(substitution[oldCharIndex]) : substitution[oldCharIndex];
        else
            output += text[i];
    }
    return output;
}

std::string atbash_cipher::decrypt(std::string text)
{
    if (!validate(text))
        return "";
    std::string substitution = "zyxwvutsrqponmlkjihgfedcba";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string output = "";
    for (size_t i{}; i < text.length(); i++)
    {

        int oldCharIndex = substitution.find(tolower(text[i]));

        if (oldCharIndex >= 0)
            output += isupper(text[i]) ? toupper(alphabet[oldCharIndex]) : alphabet[oldCharIndex];
        else
            output += text[i];
    }
    return output;

    return std::string();
}

bool atbash_cipher::validate(std::string text)
{
    for (size_t i{}; i < text.length(); i++)
    {
        if (!isalpha(text[i]))
        {
            std::cout << "Invalid string" << std::endl;
            return false;
        }
    }
    return true;
}
