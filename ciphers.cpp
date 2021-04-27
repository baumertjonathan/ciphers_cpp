// ciphers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "baconian_cipher.h"
#include "caesar_cipher.h"
#include "substitution_cipher.h"
#include "rail_fence_cipher.h"
#include "atbash_cipher.h"
#include "ROT13_cipher.h"
#include "affine_cipher.h"
#include "autokey_cipher.h"
#include "hill_cipher.h"


int main()
{
    std::cout << "Hello World!\n";
    std::vector<std::vector<int>> vectorkey 
    {
        {1, 2, 4},
        {3, 2, 6},
        {1, 4, 9}
    };
    hill_cipher cipherObj;
    std::string encrypted = cipherObj.encrypt("justtesting", vectorkey, 'x');
    std::cout << "Encrypted: " << encrypted << std::endl;
    //std::cout << "Decrypted: " << cipherObj.decrypt(encrypted, vectorkey) << std::endl;
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
