#include "linked_list.h"

class FindKToLast : public LinkedList
{
  public:
    FindKToLast(std::shared_ptr<Node> head) : LinkedList(head) {}

    void find_k_to_last(int k) { find_k_to_last(head_, k); }

    // Returning only the index and printing the corrensponding node
    int find_k_to_last(std::shared_ptr<Node> head, int k)
    {

        if (head->next == nullptr)
        {
            return 0;
        }

        int index = find_k_to_last(head->next, k) + 1;

        if (index == k)
            std::cout << "Found the " << k << "th element. It is " << head->next->data << std::endl;

        return index;
    }

    std::shared_ptr<Node> find_k_node_to_last(int k)
    {
        int i{1};
        return find_k_node_to_last(head_, k, i);
    }

    // Returning the node
    std::shared_ptr<Node> find_k_node_to_last(std::shared_ptr<Node> head, int k, int& i)
    {
        if (head->next == nullptr)
        {
            return nullptr;
        }

        std::shared_ptr<Node> n = find_k_node_to_last(head->next, k, i);

        i = i + 1;

        if (i == k)
            return head;

        return n;
    }
};

int main()
{
    std::shared_ptr<Node> head = std::make_shared<Node>(2);
    FindKToLast* linked_list = new FindKToLast(head);

    for (int i = 0; i < 10; i++)
    {
        linked_list->add_node_to_tail(rand() % 10);
    }

    linked_list->print_all_nodes();
    linked_list->find_k_to_last(5);

    std::shared_ptr<Node> n = linked_list->find_k_node_to_last(5);
    std::cout << "Found the 5th element through the node: " << n->data << std::endl;
}