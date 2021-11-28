#include "linked_list.h"
#include <vector>
#include <algorithm>


class LoopDetection : public LinkedList
{
    public:
        LoopDetection() {};
        LoopDetection(std::shared_ptr<Node> head) : LinkedList(head) {}
};

bool is_a_loop(LoopDetection& list)
{
    std::shared_ptr<Node> head = list.head_;
    std::vector<std::shared_ptr<Node>> buffer;

    while (head != nullptr)
    {
        std::vector<std::shared_ptr<Node>>::iterator it = std::find(buffer.begin(), buffer.end(), head);

        if (it != buffer.end())
        {
            std::cout << "Found loop at node: " << head->data << std::endl;
            return true;
        }
        else
        {
            buffer.push_back(head);
        } 

        head = head->next;
    }
    
    std::cout << "The list is not a loop!\n";

    return false;
}

int main()
{
    std::shared_ptr<Node> node = std::make_shared<Node>(7);
    LoopDetection loop;

    loop.add_node_to_tail(3);
    loop.add_node_to_tail(4);
    loop.add_node_to_tail(node);
    loop.add_node_to_tail(10);
    loop.add_node_to_tail(27);
    loop.add_node_to_tail(node);
    
    is_a_loop(loop);
}