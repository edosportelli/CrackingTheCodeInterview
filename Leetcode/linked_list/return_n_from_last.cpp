#include <iostream>
#include <random>

struct Node
{
    Node(int val) : value(val){};
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

Node* remove_n_from_end(Node* n, int k, int& counter)
{
    if (n->next == nullptr)
        return nullptr;

    remove_n_from_end(n->next, k, counter);
    counter += 1;

    if (counter == k + 1)
        n->next = n->next->next;

    return n;
}

int main()
{
    Node* head = new Node(255);

    for (int i = 0; i < 15; i++)
        head = add(head, rand() % 10);

    print_nodes(head);

    int counter = 0;
    head = remove_n_from_end(head, 5, counter);

    print_nodes(head);
}