/*
    Given a string s, return the longest palindromic substring in s
*/

#include <iostream>
#include <string>

struct LongString
{
    int i;
    int j;
    int lenght = 0;
};

bool is_palindrom(std::string& s, int l, int r)
{

    while (r >= l)
    {
        if (s[r] != s[l])
            return false;

        l++;
        r--;
    }

    return true;
}

std::string find_long_palindrom_n3(std::string& s)
{
    int l = 0;
    int r = s.size() - 1;
    LongString longest;

    for (l = 0; l < s.size(); l++)
    {
        while (r >= l)
        {
            std::cout << l << " " << r << std::endl;

            if (is_palindrom(s, l, r))
            {
                if ((r - l + 1) > longest.lenght)
                {
                    longest.i = l;
                    longest.j = r;
                    longest.lenght = r - l + 1;
                }
            }

            r--;
        }

        r = s.size() - 1;
    }

    std::string sub = s.substr(longest.i, longest.lenght);

    return sub;
}

bool is_palindrom_(std::string& s, int start, int& l, int& r)
{
    int i = start;
    int j = start + 1;
    int j2 = start + 2;

    if (i == 0 && s.size() == 2)
    {
        if (s[0] == s[1])
        {
            l = 0;
            r = 1;
            return true;
        }
        else 
            return false;
    }

    if (s[i] == s[j2])
    {
        while (s[i - 1] == s[j2 + 1] && i > 0 && j2 < s.size())
        {
            if (i > 0)
                i--;
            j2++;
        }

        l = i;
        r = j2;
    }
    else if (s[i] == s[j])
    {
        while (s[i - 1] == s[j + 1] && i > 0 && j < s.size())
        {
            if (i > 0)
                i--;
            j++;
        }

        l = i;
        r = j;
    }
    else
        return false;

    return true;
}

std::string find_long_palindrom(std::string& s)
{
    LongString ls;
    int l;
    int r;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (is_palindrom_(s, i, l, r))
        {
            if (r - l + 1 > ls.lenght)
            {
                ls.i = l;
                ls.j = r;
                ls.lenght = r - l + 1;
            }
        }
    }

            if (ls.lenght == 0)
        {
            std::string ret{*s.begin()};
            return ret;
        }

    return s.substr(ls.i, ls.lenght);
}

int main()
{
    std::string s = {"ccc"};

    std::string res = find_long_palindrom(s);

    std::cout << res << std::endl;
}