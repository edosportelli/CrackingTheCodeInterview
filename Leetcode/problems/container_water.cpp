
/*

    You are given an integer array height of length n. There are n vertical
    lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container
    contains the most water.
    Return the maximum amount of water a container can store.
*/

#include <iostream>
#include <vector>

int find_max_capacity(std::vector<int>& v)
{
    if (v.size() <= 1)
        return 0;

    int l = 0;
    int r = v.size() - 1;
    int res_cap = (r - l) * std::min(v[r], v[l]);
    int cap;

    while (l < r)
    {
        if (v[r] > v[l])
            l++;
        else
            r--;

        cap = (r - l) * std::min(v[r], v[l]);

        if (cap > res_cap)
            res_cap = cap;
    }

    return res_cap;
}

int main()
{
    // std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::vector<int> height{2, 3, 4, 5, 18, 17, 6};
    // std::vector<int> height{1, 2, 3, 4, 5, 25, 24, 3, 4};

    std::cout << find_max_capacity(height) << std::endl;
}
