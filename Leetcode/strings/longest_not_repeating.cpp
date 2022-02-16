/*
    Given a string s, find the length of the longest substring without repeating characters.
*/

// C++ program to find the length of the longest substring
// without repeating characters
#include <iostream>
#include <string>
#include <vector>

struct SubString
{
    int i;
    int j;
    int lenght{0};
};

SubString find_max_substrings(std::string s)
{
    int left = 0;
    int right = 0;
    SubString res;

    std::vector<std::pair<int, int>> occ(256);

    while (right < s.size())
    {
        int val = s[right];

        occ[val].first++;

        if (occ[val].first > 1)
        {
            if (occ[val].second + 1 > left)
                left = occ[val].second + 1;
                
            occ[val].first--;
            std::cout << "left: " << left << std::endl;
        }

        occ[val].second = right;

        if (right - left + 1 > res.lenght)
        {
            res.i = left;
            res.j = right;
            res.lenght = right - left + 1;
        }

        right++;
    }

    return res;
}

// Driver code
int main()
{
    SubString res;
    std::string s{"abba"};
    res = find_max_substrings(s);

    for (int i = res.i; i <= res.j; i++)
    {
        std::cout << s[i];
    }

    std::cout << res.lenght << std::endl;

    std::cout << std::endl;
}