#include "linked_list.h"

class SumLists : public LinkedList
{
  public:
    SumLists(std::shared_ptr<Node> head) : LinkedList(head){};

    std::shared_ptr<Node> sum_lists(std::shared_ptr<Node> head) { return sum_lists(head_, head, 0); }

    std::shared_ptr<Node> sum_lists(std::shared_ptr<Node> head1, std::shared_ptr<Node> head2, int rest)
    {
        if (head1 == nullptr && head2 == nullptr && rest == 0)
        {
            std::cout << "End" << std::endl;
            return nullptr;
        }

        int value = rest;

        if (head1 != nullptr)
            value += head1->data;

        if (head2 != nullptr)
            value += head2->data;

        std::shared_ptr<Node> res = std::make_shared<Node>(value % 10);
        l3->add_node_to_tail(res);

        sum_lists((head1 != nullptr) ? head1->next : nullptr, (head2 != nullptr) ? head2->next : nullptr,
                  (value >= 10) ? 1 : 0);

        return res;
    }

    void print_res()
    {
        l3->print_all_nodes();
    }

    std::unique_ptr<LinkedList> l3 = std::make_unique<LinkedList>();
};

int main()
{
    std::unique_ptr<SumLists> l1 = std::make_unique<SumLists>(std::make_shared<Node>(6));
    std::unique_ptr<SumLists> l2 = std::make_unique<SumLists>(std::make_shared<Node>(2));

    l1->add_node_to_tail(2);
    l1->add_node_to_tail(7);

    l2->add_node_to_tail(4);
    l2->add_node_to_tail(8);

    std::cout << "First list:\n";
    l1->print_all_nodes();

    std::cout << "Second list:\n";
    l2->print_all_nodes();

    std::cout << "Sum:\n";
    l1->sum_lists(l2->head_);
    l1->print_res();
}