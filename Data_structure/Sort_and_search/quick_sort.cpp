#include <vector>
#include <stdlib.h>
#include <iostream>

#define N 20
std::vector<int> v;

void sort(std::vector<int>& v)
{


}

void swap(int& a, int& b)
{
    int temp = a;

    a = b;
    b = temp;
}

void partition(std::vector<int>& v, int l, int r)
{
    int p = v[0];

    while (l <= r)
    {
        std::cout << l << " " << r << " " << v[l] << " " << v[r] << std::endl;
        for (auto& el : v)
            std::cout << el << " ";
        std::cout << std::endl;

        while (v[l] < p)
            l++;

        while (v[r] > p)
            r--;

        if (l <= r)
        {
            swap(v[l], v[r]);
            l++;
            r--;
        }

    }

    swap(v[0], v[r]);
}




int main()
{
    for (int i = 0; i < N; ++i)
        v.push_back(rand() % 10);

    for (auto& el: v)
        std::cout << el << " ";

    std::cout << std::endl;

    partition(v, 1, v.size() - 1);

    for (auto& el : v)
        std::cout << el << " ";

    std::cout << std::endl;
}