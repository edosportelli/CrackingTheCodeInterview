#include <string>
#include <memory>
#include <iostream>

#define SIZE 128

void count_characters(std::string str, int (&unicode)[SIZE])
{
    for (auto& el : str)
    {
        int val = el - 'a';
        unicode[val]++;
    }
}

bool is_permutation(std::string str1, std::string str2)
{
    int unicode1[SIZE]{0};
    int unicode2[SIZE]{0};

    count_characters(str1, unicode1);
    count_characters(str2, unicode2);

    for (int i = 0; i < SIZE; i++)
    {
        if (unicode1[i] != unicode2[i])
            return false;
    }

    return true;
}

bool is_permutation_opt(std::string str1, std::string str2)
{
    if (str1.length() != str2.length() || str1.length() > SIZE)
        return false;

    int unicode[SIZE]{0};

    for (auto& el: str1)
    {
        int val = el - 'a';
        unicode[val]++;
    }

    for (auto& el: str2)
    {
        int val = el - 'a';
        unicode[val]--;

        if (unicode[val] < 0)
            return false;
    }

    return true;
}

int main()
{
    std::cout << is_permutation_opt("ciao", "ciao") << std::endl;
    std::cout << is_permutation_opt("ciao", "bello") << std::endl;
    std::cout << is_permutation_opt("tramonto", "bello") << std::endl;
    std::cout << is_permutation_opt("ciao", "oaic") << std::endl;
}