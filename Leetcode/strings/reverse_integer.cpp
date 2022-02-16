#include <iostream>
#include <iterator>
#include <limits>
#include <string>

int main()
{
    int64_t x = 1534236469;

    std::string integer = std::to_string(x);
    std::string reverted{""};
    char minus = '-';

    if (x > std::numeric_limits<int32_t>::max() || x < std::numeric_limits<int32_t>::min())
    {
        std::cout << "Number out of range\n";
        return 0;
    }

    std::cout << x << std::endl;
    std::cout << std::numeric_limits<int32_t>::max() << std::endl;
    std::cout << std::numeric_limits<int32_t>::min() << std::endl;

    if (*integer.begin() == minus)
        reverted += "-";

    for (auto it = integer.end() - 1; it >= integer.begin(); it--)
    {
        if (*it != minus)
            reverted += *it;
    }

    std::cout << reverted << std::endl;

    return stol(reverted);
}