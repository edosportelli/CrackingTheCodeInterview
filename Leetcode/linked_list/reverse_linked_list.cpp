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

Node* revert_list(Node* head)
{
    Node* n = head;
    Node* prev = nullptr;
    Node* current = head;

    while (n->next != nullptr)
    {
        current = n;
        n = n->next;
        current->next = prev;

        prev = current;
    }

    current = n;
    current->next = prev;

    return current;
}

int main()
{
    Node* head = new Node(255);

    for (int i = 0; i < 15; i++)
        head = add(head, rand() % 10);

    print_nodes(head);

    head = revert_list(head);

    std::cout << std::endl;

    print_nodes(head);
}