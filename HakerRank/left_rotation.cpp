#include <iostream>
#include <vector>

std::vector<int> input{1, 2, 3, 4, 5};
std::vector<int> rotation;
int rot = 2;

int main()
{
    int counter {0};
    while (counter <= rot)
    {
        input.push_back(*input.begin());
        input.erase(input.begin());
        counter++;
    }

    for (auto el : input)
        std::cout << el << std::endl;
}