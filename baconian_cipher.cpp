#include "baconian_cipher.h"
#include <iostream>
#include <string>
#include <map>

std::map<char, std::string> Baconian26En{
    {'A', "aaaaa"},
    {'B', "aaaab"},
    {'C', "aaaba"},
    {'D', "aaabb"},
    {'E', "aabaa"},
    {'F', "aabab"},
    {'G', "aabba"},
    {'H', "aabbb"},
    {'I', "abaaa"},
    {'J', "abaab"},
    {'K', "ababa"},
    {'L', "ababb"},
    {'M', "abbaa"},
    {'N', "abbab"},
    {'O', "abbba"},
    {'P', "abbbb"},
    {'Q', "baaaa"},
    {'R', "baaab"},
    {'S', "baaba"},
    {'T', "baabb"},
    {'U', "babaa"},
    {'V', "babab"},
    {'W', "babba"},
    {'X', "babbb"},
    {'Y', "bbaaa"},
    {'Z', "bbaab"},
};

std::map<char, std::string> Baconian24En{
    {'A', "aaaaa"},
    {'B', "aaaab"},
    {'C', "aaaba"},
    {'D', "aaabb"},
    {'E', "aabaa"},
    {'F', "aabab"},
    {'G', "aabba"},
    {'H', "aabbb"},
    {'I', "abaaa"},
    {'J', "abaaa"},
    {'K', "abaab"},
    {'L', "ababa"},
    {'M', "ababb"},
    {'N', "abbaa"},
    {'O', "abbab"},
    {'P', "abbba"},
    {'Q', "abbbb"},
    {'R', "baaaa"},
    {'S', "baaab"},
    {'T', "baaba"},
    {'U', "baabb"},
    {'V', "baabb"},
    {'W', "babaa"},
    {'X', "babab"},
    {'Y', "babba"},
    {'Z', "babbb"},
};

std::map<std::string, char> Baconian26De{
    {"aaaaa", 'A'},
    {"aaaab", 'B'},
    {"aaaba", 'C'},
    {"aaabb", 'D'},
    {"aabaa", 'E'},
    {"aabab", 'F'},
    {"aabba", 'G'},
    {"aabbb", 'H'},
    {"abaaa", 'I'},
    {"abaab", 'J'},
    {"ababa", 'K'},
    {"ababb", 'L'},
    {"abbaa", 'M'},
    {"abbab", 'N'},
    {"abbba", 'O'},
    {"abbbb", 'P'},
    {"baaaa", 'Q'},
    {"baaab", 'R'},
    {"baaba", 'S'},
    {"baabb", 'T'},
    {"babaa", 'U'},
    {"babab", 'V'},
    {"babba", 'W'},
    {"babbb", 'X'},
    {"bbaaa", 'Y'},
    {"bbaab", 'Z'},
};

std::map<std::string, std::string> Baconian24De{
    {"aaaaa", "A"},
    {"aaaab", "B"},
    {"aaaba", "C"},
    {"aaabb", "D"},
    {"aabaa", "E"},
    {"aabab", "F"},
    {"aabba", "G"},
    {"aabbb", "H"},
    {"abaaa", "(I/J)"},
    {"abaab", "K"},
    {"ababa", "L"},
    {"ababb", "M"},
    {"abbaa", "N"},
    {"abbab", "O"},
    {"abbba", "P"},
    {"abbbb", "Q"},
    {"baaaa", "R"},
    {"baaab", "S"},
    {"baaba", "T"},
    {"baabb", "(U/V)"},
    {"babaa", "W"},
    {"babab", "X"},
    {"babba", "Y"},
    {"babbb", "Z"},
};

std::string baconian_cipher::encrypt24(std::string text)
{
    std::cout << "enrypting: " << text << std::endl;
    std::string result = "";
    
    for (size_t i{}; i < text.length(); i++)
    {
        result += Baconian24En[toupper(text[i])];
    }
    return result;
}

std::string baconian_cipher::decrypt24(std::string text)
{
    std::string result = "";
    std::string temp = "";
    for (size_t i{}; i < text.length(); ++i)
    {
        while (temp.length() < 5)
        {
            temp += text[i];
            i++;
        }      
        result += Baconian24De[temp];
        temp = "";
        i--;
    }
    std::cout << Baconian24De["baaba"] << std::endl;
    return result;
}

std::string baconian_cipher::encrypt26(std::string text)
{
    std::string result = "";

    for (size_t i{}; i < text.length(); i++)
    {
        result += Baconian26En[toupper(text[i])];
    }
    return result;
}

std::string baconian_cipher::decrypt26(std::string text)
{
    std::string result = "";
    std::string temp = "";
    for (size_t i{}; i < text.length(); ++i)
    {
        while (temp.length() < 5)
        {
            temp += text[i];
            i++;
        }
        result += Baconian26De[temp];
        temp = "";
        i--;
    }
    return result;
}