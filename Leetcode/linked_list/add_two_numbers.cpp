/*
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.
*/

#include <iostream>

struct Node
{
    Node(){};
    Node(int val_) : val(val_) {}
    int val;
    Node* next;
};

Node* add(Node* head, int val)
{
    if (head == nullptr)
        return new Node(val);

    Node* n = head;

    while (n->next != nullptr)
    {
        n = n->next;
    }

    n->next = new Node(val);

    return head;
}

Node* sum(Node* n1, Node* n2, int& rest)
{
    if (n1 == nullptr && n2 == nullptr && rest == 0)
        return nullptr;

    Node* res = new Node();

    int val = rest;

    if (n1 != nullptr)
        val += n1->val;

    if (n2 != nullptr)
        val += n2->val;

    rest = (val >= 10) ? 1 : 0;
    res->val = (rest > 0) ? val - 10 : val;

    Node* next = sum((n1 != nullptr) ? n1->next : nullptr, (n2 != nullptr) ? n2->next : nullptr, rest);
    res->next = next;

    return res;
}

void print_nodes(Node* head)
{
    Node* to_print = head;
    while (true)
    {
        std::cout << to_print->val << std::endl;
        to_print = to_print->next;

        if (to_print == nullptr)
            break;
    }
}

int main()
{
    Node* head1 = new Node(2);
    Node* head2 = new Node(5);

    head1 = add(head1, 4);
    head1 = add(head1, 3);
    head1 = add(head1, 1);

    head2 = add(head2, 6);
    head2 = add(head2, 4);

    int rest = 0;
    Node* head3 = sum(head1, head2, rest);

    // print_nodes(head1);
    // print_nodes(head2);
    print_nodes(head3);
}