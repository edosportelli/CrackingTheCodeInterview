#include "linked_list.h"

class Palindrom : public LinkedList
{
    public:
        Palindrom() {}
        Palindrom(std::shared_ptr<Node> head) : LinkedList(head) {}

        void revert()
        {
            std::shared_ptr<Node> store_head = head_;

            while(head_ != nullptr)
            {
                std::shared_ptr<Node> n = std::make_shared<Node>(head_->data);

                n->next = reverted->head_;
                reverted->head_ = n;    
                
                head_ = head_->next;
            }

            std::cout << "Reverted list:\n";
            reverted->print_all_nodes();
            head_ = store_head;
        }

        bool is_equal()
        {
            while (head_ != nullptr)
            {
                if (head_->data != reverted->head_->data)
                {
                    std::cout << "The list in NOT palindrom!\n";
                    return false;
                }
            
                head_ = head_->next;
                reverted->head_ = reverted->head_->next;
            }

            std::cout << "The list is palindrom!\n";
            return true;
        }

        std::unique_ptr<LinkedList> reverted = std::make_unique<LinkedList>();
};

int main()
{
    Palindrom p;

    p.add_node_to_tail(1);
    p.add_node_to_tail(2);
    p.add_node_to_tail(2);
    p.add_node_to_tail(1);
    std::cout << "Initial list:\n";
    p.print_all_nodes();
    p.revert();

    p.is_equal();
}