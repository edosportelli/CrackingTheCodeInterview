#include <iostream>
#include <vector>

#define N 3

class ThreeInOne
{
  public:
    ThreeInOne()
    {
        stack = new int[N];
        stack_size = N;
    }

    void push(int item, int stack_num)
    {
        if (stack_size == tot_items)
        {
            resize(stack_size * 2);
        }

        switch (stack_num)
        {
        case 0:
            stack[items[0]++] = item;
            break;

        case 1:
            stack[items[1] + stack_size / N] = item;
            items[1]++;
            break;

        case 2:
            stack[items[2] + stack_size * 2 / N] = item;
            items[2]++;
            break;

        default:
            std::cout << "Wrong stack num!\n";
            return;
        }

        tot_items++;
    }

    void resize(int new_size)
    {
        std::cout << "Calling the resising with new size: " << new_size << std::endl;

        int* new_stack = new int[new_size];

        for (int i = 0; i < items[0]; ++i)
            new_stack[i] = stack[i];

        for (int i = 0; i < items[1]; ++i)
            new_stack[i + new_size / 3] = stack[i + stack_size / 3];

        for (int i = 0; i < items[2]; ++i)
            new_stack[i + new_size * 2 / 3] = stack[i + stack_size * 2 / 3];

        stack = new_stack;
        stack_size = new_size;
    }

    int pop(int stack_num)
    {
        tot_items--;

        switch (stack_num)
        {
        case 0:
            return stack[--items[stack_num]];

        case 1:
            return stack[--items[stack_num] + stack_size / N];

        case 2:
            return stack[--items[stack_num] + stack_size * 2 / N];

        default:
            std::cout << "Wrong stack num!\n";
            break;
        }
    }

    void print()
    {
        for (int i = 0; i < stack_size; ++i)
        {
            std::cout << stack[i] << std::endl;
        }
    }

  private:
    int* stack;
    int stack_size;
    int items[N] = {0};
    int tot_items{0};
};

int main()
{
    ThreeInOne stack;

    int range = 10;

    for (int i = 0; i < range; i++)
    {
        stack.push(i, 0);
        stack.push(i + range, 1);
        stack.push(i + range * 2, 2);
    }

    stack.print();

    // std::cout << stack.pop(0) << std::endl;
    // std::cout << stack.pop(0) << std::endl;
    // std::cout << stack.pop(0) << std::endl;
    // std::cout << stack.pop(1) << std::endl;
    // std::cout << stack.pop(1) << std::endl;
}
