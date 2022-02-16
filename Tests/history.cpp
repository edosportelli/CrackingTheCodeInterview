// Write elements from the input range to the output if they did not appear
// in the previous `history_size` elements.
//
// Example 1 (history_size = 3): [a, b, a, a, c, b] => [a, b, c, b]
// Example 2 (history_size = 0): [a, a, b] => [a, a, b]
//
// @tparam InputIt meets the requirements of LegacyInputIterator
// @tparam OutputIt meets the requirements of LegacyOutputIterator.
//
// @param [in] first The beginning of input range.
// @param [in] last The end of input range.
// @param [in/out] d_first The beginning of destination range.
// @param [in] history_size Filter history size.
//
// @return The end of output range.

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

int filter(std::string::iterator first, std::string::iterator last, std::string& output, int history)
{
    std::unordered_map<char, int> map;

    for (auto it = first; it != last; it++)
    {
        if (it - first >= history)
        {
            map[*(it - history)]--;
        }

        if (map[*it] == 0)
            output += *it;

        map[*it] += 1;
        for (auto item : map)
            std::cout << item.first << " " << item.second << std::endl;

        std::cout << std::endl;
    }

    return output.size();
}

int main()
{
    std::string input{"abaaaaabbbc"};
    std::string output{""};
    int history = 3;

    int res = filter(input.begin(), input.end(), output, history);

    // assert(res, output.size());
    std::cout << input << std::endl;
    std::cout << output << std::endl;
}
