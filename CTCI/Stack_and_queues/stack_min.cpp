#include <limits>
#include <iostream>

class StackMin
{
  public:
    StackMin() {}

    void push(int x)
    {
        if (x < min)
            min = x;

        Node* old_first = first;
        first = new Node;

        first->value = x;
        first->min = min;
        first->next = old_first;
    }

    int pop()
    {
        if (first != nullptr)
        {
            int value = first->value;
            first = first->next;

            if (value == min)
                min = first->min;

            return value;
        }
    }

    int get_min() { return min; }

  private:
    struct Node
    {
        int value;
        Node* next;
        int min;
    };

    int min = std::numeric_limits<int>::max();
    Node* first = nullptr;
};

int main()
{
    StackMin stack;
    stack.push(50);
    stack.push(6);
    stack.push(11);
    stack.push(24);
    stack.push(4);
    stack.push(12);

    std::cout << stack.get_min() << std::endl;
    stack.pop();
    std::cout << stack.get_min() << std::endl;
    stack.pop();
    std::cout << stack.get_min() << std::endl;
    stack.pop();
    std::cout << stack.get_min() << std::endl;
    stack.pop();
    std::cout << stack.get_min() << std::endl;
    stack.pop();
    std::cout << stack.get_min() << std::endl;
}