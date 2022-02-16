/*

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

*/

#include <iostream>
#include <vector>

void merge_sort(std::vector<int>& v1, std::vector<int>& v2, int num1, int num2)
{
    int index{num1 + num2 - 1};

    while (index >= 0)
    {
        if (num2 == 0)
            break;

        if (v2[num2 - 1] >= v1[num1 - 1])
        {
            v1[index] = v2[num2 - 1];
            num2--;
        }
        else
        {
            v1[index] = v1[num1 - 1];
            num1--;
        }

        index--;
    }
}

int main()
{
    std::vector<int> v1{1, 2, 3, 0, 0, 0};
    std::vector<int> v2{2, 5, 6};

    merge_sort(v1, v2, 3, 3);

    for (auto item : v1)
        std::cout << item << std::endl;
}