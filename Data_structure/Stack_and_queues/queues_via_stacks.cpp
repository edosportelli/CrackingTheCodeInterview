#include "stack.hpp"

class QueuesViaStacks
{
  public:
    QueuesViaStacks() {}

    void enqueue(int value) { s1.push(value); }

    int dequeue()
    {
        while (s1.get_first() != nullptr)
        {
            int value = s1.pop();
            s2.push(value);
        }

        std::cout << "Popping: " << s2.pop() << std::endl;
    }

  private:
    Stack<int> s1;
    Stack<int> s2;
};

int main()
{
    QueuesViaStacks queue;

    int range = 10;

    for (int i = 0; i < range; ++i)
        queue.enqueue(i);
 
    for (int i = 0; i < range + 4; ++i)
        queue.dequeue();

    for (int i = 0; i < range; ++i)
        queue.enqueue(i);

    for (int i = 0; i < range + 4; ++i)
        queue.dequeue();
}
