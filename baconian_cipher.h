#pragma once
#include <string>

class baconian_cipher
{
public:
    std::string encrypt24(std::string text);
    std::string decrypt24(std::string text);
    std::string encrypt26(std::string text);
    std::string decrypt26(std::string text);
};

