#include <iostream>
#include <set>
#include <vector>

int remove_duplicated(std::vector<int>& v)
{
    int prev = v[0];
    int index{0};

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != prev)
        {
            index++;
            if (index != i)
                v[index] = v[i];
            
        }

        prev = v[i];
    }

    v.resize(index + 1);
    return index + 1;
}

int main()
{
    std::vector<int> v{1, 2, 2, 2, 3, 4, 4, 4, 5, 5, 6, 7, 8, 10};

    remove_duplicated(v);

    for (auto item : v)
        std::cout << item << std::endl;
}