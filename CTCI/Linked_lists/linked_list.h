#pragma once

#include <iostream>
#include <memory>

class Node
{
  public:
    std::shared_ptr<Node> next = nullptr;
    int data;

    Node() {}
    Node(int d) : data{d} {}
};

class LinkedList
{
  protected:

  public:
    std::shared_ptr<Node> head_ = nullptr;
    
    LinkedList() {};
    LinkedList(std::shared_ptr<Node> head) : head_{head} {}

    void add_node_to_tail(std::shared_ptr<Node> node)
    {
        if (node == nullptr)
            return;

        if (head_ == nullptr)
        {
            head_ = node;
            return;
        }

        std::shared_ptr<Node> n = head_;

        while (n->next != nullptr)
        {
            n = n->next;
        }
        n->next = node;
    }

    void add_node_to_tail(int d)
    {
        std::shared_ptr<Node> n = std::make_shared<Node>(d);
        add_node_to_tail(n);
    }

    void remove_node(int d)
    {
        if (head_ == nullptr)
            return;

        if (head_->data == d)
        {
            head_ = head_->next;
            return;
        }

        std::shared_ptr<Node> n = head_;

        while (n->next != nullptr)
        {
            if (n->next->data == d)
            {
                n->next = n->next->next;
            }
            else
            {
                n = n->next;
            }
        }
    }

    void print_all_nodes()
    {
        std::shared_ptr<Node> n = head_;

        while (true)
        {
            if (n == nullptr)
                break;
                
            std::cout << n->data << " " << n << std::endl;


            n = n->next;
        }
    }
};