#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define N 10000000
#define T 30

int find_bad_version(std::vector<bool>& v, std::unordered_map<int, bool>& map, int l, int r)
{
    int mid = l + (r - l) / 2;

    std::cout << l << " " << r << " " << mid << std::endl;

    if (r <= l)
    {
        return mid;
    }

    if (v[mid] == false)
        find_bad_version(v, map, mid + 1, r);
    else
        find_bad_version(v, map, l, mid);
}

int main()
{
    std::vector<bool> v;
    std::unordered_map<int, bool> map;

    for (int i = 0; i < N; i++)
    {
        if (i < T)
            v.push_back(false);
        else
            v.push_back(true);
    }

    std::cout << find_bad_version(v, map, 0, v.size()) << std::endl;
}