#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

bool is_valid_string(std::string& str)
{
    std::stack<char> stack;

    for (auto& el : str)
    {
        if (el == '(' || el == '[' || el == '{')
        {
            stack.push(el);
        }
        else if (stack.empty())
        {
            std::cout << "First element cannot be a closing bracket!\n";
            return false;
        }
        else
        {
            auto item = stack.top();

            switch (el)
            {
            case ')':
                if (item != '(')
                    return false;
                break;

            case ']':
                if (item != '[')
                    return false;
                break;

            case '}':
                if (item != '{')
                    return false;
                break;
            }

            stack.pop();
        }
    }

    std::cout << "The string is valid\n";

    return true;
}

int main()
{
    std::string s = {"{[{()}]}"}; // yes

    is_valid_string(s);
}