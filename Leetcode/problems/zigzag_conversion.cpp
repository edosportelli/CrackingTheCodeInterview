/*
    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"
*/

#include <iostream>
#include <string>

// std::string s = "PAYPALISHIRING";
std::string s = "AB";

std::string zigzag_conv(std::string& s, int num_rows)
{
    std::string conversion;

    if (s.size() <= num_rows)
    {
        return s;
    }

    if (num_rows == 1)
        return s;

    for (int i = 0; i < num_rows; i++)
    {
        int j = i;

        if (i == 0 || i == num_rows - 1)
        {
            conversion += s[j];
            while (j < s.size())
            {
                j += (num_rows - 1) * 2;
                if (j < s.size())
                    conversion += s[j];
            }
        }
        else
        {
            conversion += s[j];
            while (j < s.size())
            {
                j += (num_rows - 1) * 2 - 2 * i;
                if (j < s.size())
                    conversion += s[j];

                j += 2 * i;
                if (j < s.size())
                    conversion += s[j];
            }
        }
    }

    return conversion;
}

int main()
{
    std::string res = zigzag_conv(s, 3);

    std::cout << res << std::endl;
}