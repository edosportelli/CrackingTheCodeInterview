/* Enqueue the last element and dequeue the first */

#include <iostream>
#include <string>

struct Node
{
    std::string item;
    Node* next = nullptr;
};

class Queue
{
  public:
    Queue() {}

    void enqueue(std::string s)
    {
        Node* old_last = last;
        last = new Node;
        last->item = s;
        last->next = nullptr;

        if (first == nullptr)
            first = last;
        else
            old_last->next = last;
    }

    std::string dequeue()
    {
        if (first != nullptr)
        {
            std::string item = first->item;
            first = first->next;

            return item;
        }

        return "Queue is empty!\n";
    }

  private:
    Node* first = nullptr;
    Node* last = nullptr;
};

int main()
{
    Queue queue;

    queue.enqueue("ciao");
    queue.enqueue("mi");
    queue.enqueue("chiamo");
    queue.enqueue("edo");

    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";

    queue.enqueue("ciao");
    queue.enqueue("mi");
    queue.enqueue("chiamo");
    queue.enqueue("edo");

    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
}
