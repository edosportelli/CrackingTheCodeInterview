#include "linked_list.h"
#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<Node> head = std::make_shared<Node>(2);
    LinkedList* linked_list = new LinkedList(head);

    linked_list->add_node_to_tail(10);
    linked_list->add_node_to_tail(14);
    linked_list->add_node_to_tail(25);
    linked_list->add_node_to_tail(7);
    linked_list->add_node_to_tail(13);
    linked_list->add_node_to_tail(8);
    linked_list->add_node_to_tail(16);
    linked_list->print_all_nodes();

    std::cout << "/* --- After removing --- */" << std::endl;

    linked_list->remove_node(2);
    linked_list->remove_node(25);
    linked_list->remove_node(13);
    linked_list->remove_node(8);
    linked_list->print_all_nodes();
}