#include "hill_cipher.h"


std::string hill_cipher::encrypt(std::string text, std::vector<std::vector<int>> key, char filler = 'x')
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string result = "";
    size_t i{};
    // extend the text
    if (text.length() % key.size())
    {
        for (int i = 0; i < (text.length() % key.size()); i++)
        {
            text += filler;
        }
    }
    //split into sets of vector size
    std::vector<std::vector<int>> splitholder;
    std::vector<int> temp;
    while (i < text.length())
    {
        temp.clear();
        for (size_t j{}; j < key.size(); j++)
        {
            temp.push_back(alphabet.find(tolower(text[i + j])));
        }
        i += key.size();
        splitholder.push_back(temp);
    }
    /*for (size_t i{}; i < splitholder.size(); i++)
    {
        for (size_t j{}; j < splitholder[i].size(); i++)
        {
            std::cout << splitholder[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    // matrix multiplication
    std::cout << "matrix multiplication" << std::endl;
    for (size_t i{}; i < splitholder.size(); i++)
    {
        std::vector<int> temp = matrixmultiplication(key, splitholder[i]);
        for (size_t j{}; j < temp.size(); j++)
        {
            std::cout << temp[j] << " ";
        }
    }

    return std::string();
}

std::string hill_cipher::decrypt(std::string text, std::vector<std::vector<int>> key)
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    return std::string();
}

bool hill_cipher::validatekey(std::vector<std::vector<int>> key)
{
    //check if it is square

    return false;
}

std::vector<int> hill_cipher::matrixmultiplication(std::vector<std::vector<int>> mat1, std::vector<int> mat2)
{
    int temp = 0;
    std::vector<int> result;
    for (size_t i{}; i < mat1.size(); i++)
    {
        temp = 0;
        for (size_t j{}; j < mat1[i].size(); j++)
        {
            temp += (mat1[i][j] * mat2[j]);
        }
        //std::cout << temp; 
        result.push_back(temp);
    }

    return result;
}