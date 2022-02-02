#pragma once

#include <iostream>
#include <string>

struct Node
{
    int item;
    Node* next;
};

template <typename T>
class Stack
{
  public:
    Stack() {}

    T pop()
    {
        if (first != nullptr)
        {
            T item = first->item;
            first = first->next;

            items--;

            return item;
        }

        // return "Stack is empty!\n";
    }

    void push(T item)
    {
        Node* old_first = first; // store last first node
        first = new Node;
        first->item = item;
        first->next = old_first;

        items++;
    }

    int items{0};

    Node* get_first() { return first; }
    void set_first(Node* n) { first = n; }

  private:
    Node* first = nullptr;
};