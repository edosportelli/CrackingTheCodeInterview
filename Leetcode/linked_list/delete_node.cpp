#include <iostream>

struct Node
{
    Node(int value_) : value(value_) {}
    int value;
    Node* next;
};

Node* add(Node* head, int value)
{
    Node* to_add = head;

    while (to_add->next != nullptr)
    {
        to_add = to_add->next;
    }

    to_add->next = new Node(value);

    return head;
}

void print_nodes(Node* head)
{
    Node* to_print = head;
    while (true)
    {
        std::cout << to_print->value << std::endl;
        to_print = to_print->next;

        if (to_print == nullptr)
            break;
    }
}

Node* delete_node(Node* head, int value_)
{
    Node* to_delete = head;

    if (to_delete->value == value_)
        return to_delete->next;

    while (to_delete->next != nullptr)
    {
        if (to_delete->next->value == value_)
            to_delete->next = to_delete->next->next;
        else
            to_delete = to_delete->next;
    }

    return head;
}

int main()
{
    Node* head = new Node(10);

    add(head, 1);
    add(head, 2);
    add(head, 3);
    add(head, 4);

    print_nodes(head);

    head = delete_node(head, 3);
    print_nodes(head);

    head = delete_node(head, 10);
    print_nodes(head);
}