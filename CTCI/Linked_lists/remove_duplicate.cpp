#include "linked_list.h"
#include <algorithm>
#include <memory>
#include <vector>

class LinkedListDuplicate : public LinkedList
{
  public:
    LinkedListDuplicate(std::shared_ptr<Node> head) : LinkedList(head){};

    void remove_duplicated()
    {
        std::vector<int> buffer;
        buffer.push_back(head_->data);

        std::shared_ptr<Node> n = head_;

        while (n->next != nullptr)
        {
            std::vector<int>::iterator it = std::find(buffer.begin(), buffer.end(), n->next->data);

            if (it != buffer.end())
            {
                n->next = n->next->next;
            }
            else
            {
                buffer.push_back(n->next->data);
                n = n->next;
            }
        }
    }
};

int main()
{
    std::shared_ptr<Node> head = std::make_shared<Node>(2);
    LinkedListDuplicate* linked_list = new LinkedListDuplicate(head);

    for (int i = 0; i < 10; i++)
    {
        linked_list->add_node_to_tail(rand() % 10);
    }

    linked_list->print_all_nodes();
    linked_list->remove_duplicated();
    std::cout << "/* --- After removing duplicated --- */" << std::endl;
    linked_list->print_all_nodes();
}