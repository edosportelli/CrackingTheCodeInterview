#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define N 11

std::string list[N] = {"ciao", "mi", "chiamo", "edo", "oppure", "anche", "ode", "oaic", "im", "deo", "omicron"};

void sort_word(std::string& word /*, int l, int r*/)
{
    std::sort(word.begin(), word.end());
}

bool comparator(std::pair<int, std::string>& it1, std::pair<int, std::string>& it2)
{
    return it1.second < it2.second;
}

std::vector<std::string> sort_with_hash_table()
{
    std::unordered_map<std::string, std::vector<std::string>> hash_table;

    for (int i = 0; i < N; i++)
    {
        std::string anagram = list[i];
        sort_word(anagram);

        hash_table[anagram].push_back(list[i]);
    }

    std::vector<std::string> ret;
    for (auto& el : hash_table)
    {
        std::vector<std::string> list = el.second;

        for (auto item : list)
            ret.push_back(item);
    }

    return ret;
}

int main()
{
    std::vector<std::pair<int, std::string>> v;

    for (int i = 0; i < N; i++)
    {
        v.push_back(std::pair<int, std::string>(i, list[i]));
        sort_word(v[i].second);
    }

    std::sort(v.begin(), v.end(), comparator);

    for (auto it = v.begin(); it != v.end(); it++)
        std::cout << list[it->first] << std::endl;

    std::vector<std::string> ret = sort_with_hash_table();

    std::cout << std::endl;
    for (auto el : ret)
        std::cout << el << std::endl;
}
