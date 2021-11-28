#include "linked_list.h"

class Partition : public LinkedList
{
    public:
        Partition(std::shared_ptr<Node> head) : LinkedList (head) {}

        void split(int k) { return split(head_, k); }

        void split(std::shared_ptr<Node> head, int k)
        {
            while(true)
            {
                auto n = head;

                if(n->data < k)
                {
                    if(left == nullptr)
                    {
                        left = std::make_unique<LinkedList>(n);
                        left_last = n;
                    }
                    else 
                    {
                        left_last->next = n;
                        left_last = n;
                    }
                }
                else 
                {
                    if (right == nullptr)
                    {
                        right = std::make_unique<LinkedList>(n);
                        right_last = n;
                    }
                    else
                    {
                        right_last->next = n;
                        right_last = n;
                    }
                }

                head = head->next;

                if (head->next == nullptr)
                {
                    left_last->next = nullptr;
                    right_last->next = nullptr;
                    break;
                }

            }

            std::cout << "Value before " << k << ": " << std::endl;
            left->print_all_nodes();
            std::cout << "Value after " << k << ": " << std::endl;
            right->print_all_nodes();
        }



    protected:
        std::unique_ptr<LinkedList> left;
        std::unique_ptr<LinkedList> right;
        std::shared_ptr<Node> left_last;
        std::shared_ptr<Node> right_last;
};

int main()
{
    std::shared_ptr<Node> head = std::make_shared<Node>(2);
    Partition* linked_list = new Partition(head);

    for (int i = 0; i < 10; i++)
    {
        linked_list->add_node_to_tail(rand() % 10);
    }

    linked_list->print_all_nodes();
    linked_list->split(5);
    
}