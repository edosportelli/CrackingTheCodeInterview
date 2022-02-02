#include "stack.hpp"
#include <iostream>
#include <vector>

class StackOfPlates
{
  public:
    StackOfPlates() { stacks.push_back(Stack<int>()); }

    void push(int value)
    {
        if (stacks[stack_id].items > threshold)
            stack_id++;

        if (stacks.size() == stack_id)
            stacks.push_back(Stack<int>());

        stacks[stack_id].push(value);
    }

    int pop()
    {
        int value = stacks[stack_id].pop();

        std::cout << "Removing " << value << " from stack " << stack_id << std::endl;

        if (stacks[stack_id].items == 0)
        {
            if (stack_id > 0)
                stack_id--;
            stacks.pop_back();
        }
    }

  private:
    std::vector<Stack<int>> stacks;
    size_t stack_id{0};
    int threshold = 1;
};

int main()
{
    StackOfPlates stack;

    int range = 10;

    for (int i = 0; i < range; ++i)
        stack.push(i);

    for (int i = 0; i < range + 4; ++i)
        stack.pop();

    for (int i = 0; i < range; ++i)
        stack.push(i);

    for (int i = 0; i < range + 4; ++i)
        stack.pop();
}