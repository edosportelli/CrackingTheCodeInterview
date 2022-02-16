/*

Given a string s, find the first non-repeating character in it and return its index.
If it does not exist, return -1.

*/

#include <iostream>
#include <limits>
#include <string>
#include <vector>

int find_first_unique(std::string& s)
{
    std::vector<std::pair<int, int>> counter(256);

    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        counter[index].first++;
        counter[index].second = i;
    }

    int res = std::numeric_limits<int>::max();

    for (int i = 0; i < counter.size(); i++)
    {
        if (counter[i].first == 1 && counter[i].second < res)
            res = counter[i].second;
    }

    return res;
}

int main()
{
    std::string s{"leetcode"};
    // std::string s{"loveleetcode"};

    std::cout << find_first_unique(s) << std::endl;
}