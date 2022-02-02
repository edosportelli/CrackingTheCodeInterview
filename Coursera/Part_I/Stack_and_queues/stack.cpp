#include <iostream>
#include <string>
#include <vector>

struct Node
{
    std::string item;
    Node* next;
};

class Stack
{
  public:
    Stack() {}

    std::string pop()
    {
        if (first != nullptr)
        {
            std::string item = first->item;
            first = first->next;
            return item;
        }

        return "Stack is empty!\n";
    }

    void push(std::string item)
    {
        Node* old_first = first; // store last first node
        first = new Node;
        first->item = item;
        first->next = old_first;
    }

  private:
    Node* first = nullptr;
};

class StackArray
{
  public:
    StackArray(uint size) { stack.reserve(size); }

    std::string pop()
    {
        if (N > 0)
            return stack[--N];

        return "Stack empty!\n";
    }

    void push(std::string s) { stack[N++] = s; }

  private:
    std::vector<std::string> stack;
    uint N{0};
};

int main()
{
    StackArray stack(10);

    stack.push("ciao");
    stack.push("mi");
    stack.push("chiamo");
    stack.push("edo");

    std::cout << stack.pop() << " ";
    std::cout << stack.pop() << " ";
    std::cout << stack.pop() << " ";
    std::cout << stack.pop() << " ";
    std::cout << stack.pop() << " ";
    std::cout << stack.pop() << " ";
    std::cout << stack.pop() << " ";
}