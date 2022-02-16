#include <algorithm>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <vector>

#define N 20
std::vector<int> v;

void swap(int& a, int& b)
{
    int temp = a;

    a = b;
    b = temp;
}

int partition(std::vector<int>& v, int l, int r)
{
    int p_i = l;
    int p = v[p_i];
    l += 1;

    std::cout << "called " << p_i << std::endl;

    while (l <= r)
    {
        while (v[l] < p && l <= r)
            l++;

        while (v[r] > p && r >= l)
            r--;

        if (l <= r)
        {
            swap(v[l], v[r]);
            l++;
            r--;
        }
    }

    swap(v[p_i], v[r]);

    std::cout << "Ret " << r << std::endl;
    return r;
}

int selection(std::vector<int>& v, int l, int r, int k)
{
    int p = partition(v, l, r);

    for (auto& el : v)
        std::cout << el << " ";

    std::cout << std::endl;

    if (p == k)
        return v[p];
    else if (p >= k)
        selection(v, l, p - 1, k);
    else 
        selection(v, p + 1, r, k);
}

int main()
{
    for (int i = 0; i < N; ++i)
        v.push_back(rand() % 10);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);

    for (auto& el : v)
        std::cout << el << " ";

    std::cout << std::endl;

    // partition(v, 0, v.size() - 1);
    int k = selection(v, 0, v.size() - 1, 13);

    std::cout << k << std::endl;
}