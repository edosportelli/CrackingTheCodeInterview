/* There is a collection of input strings and a collection of query strings.
For each query string, determine how many times it occurs in the list of input strings.
Return an array of the results. */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<string> strings{"ab", "ab", "abc"};
vector<string> queries{"ab", "abc", "bc"};

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    std::vector<int> res(queries.size());
    std::unordered_multiset<std::string> set;

    for (auto& item : strings)
        set.insert(item);

    for (int i = 0; i < queries.size(); i++)
        res[i] = set.count(queries[i]);

    return res;
}

int main()
{
    std::vector<int> res = matchingStrings(strings, queries);

    for (auto item : res)
        std::cout << item << std::endl;
}
