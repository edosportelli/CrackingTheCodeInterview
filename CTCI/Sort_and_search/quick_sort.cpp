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
    return r;
}

void quick_sort(std::vector<int>& v, int l, int r)
{
    if (r <= l)
        return;

    int p = partition(v, l, r);
    quick_sort(v, l, p - 1);
    quick_sort(v, p + 1, r);
}

int selection(std::vector<int>& v, int l, int r, int k)
{
    if (r <= l)
        return 0;

    int p = partition(v, l, r);

    if (p == k)
        return v[p];

    quick_sort(v, l, p - 1);
    quick_sort(v, p + 1, r);
}

int main()
{
    for (int i = 0; i < N; ++i)
        v.push_back(rand() % 10);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);

    for (auto& el: v)
        std::cout << el << " ";

    std::cout << std::endl;

    // partition(v, 0, v.size() - 1);
    quick_sort(v, 0, v.size() - 1);

    for (auto& el : v)
        std::cout << el << " ";

    std::cout << std::endl;
}