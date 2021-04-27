#include <iostream>

std::string encrypt(std::string text, int s)
{
    std::string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }
    return result;
}

std::string decrypt(std::string text, int s)
{
    std::string result = "";
    s = -s;
    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }
    return result;
}

int main()
{
    std::string text = "ATTACKATONCE";
    int s = 4;
    std::cout << "Text : " << text;
    std::cout << "\nShift: " << s;
    std::cout << "\nCipher: " << encrypt(text, s);

    return 0;
}