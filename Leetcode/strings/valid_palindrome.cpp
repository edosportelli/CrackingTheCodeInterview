#include <iostream>
#include <string>

bool is_palindrom(std::string& s)
{
    int l = 0;
    int r = s.size() - 1;

    while (r >= l)
    {
        while (not isalpha(s[l]))
            l++;

        while (not isalpha(s[r]))
            r--;

        if (isupper(s[l]))
            s[l] = tolower(s[l]);

        if (isupper(s[r]))
            s[r] = tolower(s[r]);

        if (s[l] != s[r])
        {
            std::cout << s[l] << " " << s[r] << std::endl;
            return false;
        }

        l++;
        r--;
    }

    return true;
}

int main()
{
    std::string s{"A man, a plan, a canal: Panama"};

    std::cout << is_palindrom(s) << std::endl;
}