#include <boost/functional/hash.hpp>
#include <iostream>
#include <memory>
#include <string>

#define SIZE 128

bool unicode[SIZE] {false};


bool is_unique(std::string str)
{
    if (str.length() > 128)
        return false;

    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i] - 'a';     // get index in the array. a is 0, b is 1 and so on

        if (unicode[val])
        {
            return false;
        }
        else 
        {
            unicode[val] = true;
        }
        
        return true;
    }
}

int main()
{
    std::cout << "String 'ciao' is unique: " << is_unique("ciao") << std::endl;
    std::cout << "String 'ciao bello' is unique: " << is_unique("ciao bello") << std::endl;
}