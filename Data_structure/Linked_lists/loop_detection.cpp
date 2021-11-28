#include "linked_list.h"
#include <vector>
#include <algorithm>

#define K 20
#define LOOP_LENGHT 5

class LoopDetection : public LinkedList
{
    public:
        LoopDetection() {};
        LoopDetection(std::shared_ptr<Node> head) : LinkedList(head) {}
};

bool is_a_loop(LoopDetection& list)
{
    std::shared_ptr<Node> slow = std::make_shared<Node>();
    std::shared_ptr<Node> fast = std::make_shared<Node>();

    slow = list.head_;
    fast = list.head_;

    while (true)
    {
        if (fast == nullptr)
        {
            std::cout << "There is no looop!\n";
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            std::cout << "Collision point is node: " << fast->data << " " << fast << std::endl;
            break;
        }
    }

    slow = list.head_;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    std::cout << "Loop start at node: " << fast->data << " " << fast << std::endl;

    return true;
}

int main()
{
    std::shared_ptr<Node> node = std::make_shared<Node>(7);
    LoopDetection loop;

    for (int i = 0; i < K; i++)
    {
        std::shared_ptr<Node> n = std::make_shared<Node>(rand() % 10 + i);
        loop.add_node_to_tail(n);
    }

    loop.add_node_to_tail(node);

    for (int i = 0; i < LOOP_LENGHT; i++)
    {
        std::shared_ptr<Node> n = std::make_shared<Node>(rand() % 10 + i);
        loop.add_node_to_tail(n);
    }

    loop.add_node_to_tail(node);
    is_a_loop(loop);
}