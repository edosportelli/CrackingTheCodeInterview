#pragma once

#include <iostream>

struct Node
{
    Node(int key_, int depth_) : key(key_), depth(depth_) {}
    int key;
    int value;

    Node* left = nullptr;
    Node* right = nullptr;

    int count{1};
    int depth;
};

int size(Node* n)
{
    if (n == nullptr)
        return 0;

    return n->count;
}

Node* add(Node* n, int key, int depth)
{
    if (n == nullptr)
    {
        // std::cout << "Creating node " << key << " depth: " << depth << std::endl;
        return new Node(key, depth);
    }

    if (key < n->key)
    {
        // std::cout << key << " less than " << n->key << std::endl;
        n->left = add(n->left, key, n->depth + 1);
    }
    else if (key > n->key)
    {
        // std::cout << key << " greater than " << n->key << std::endl;
        n->right = add(n->right, key, n->depth + 1);
    }
    else
    {
        // std::cout << key << " ---- already exists!\n";
    }

    n->count = 1 + size(n->left) + size(n->right);

    return n;
}

void print_node(Node* n)
{
    std::cout << "Key: " << n->key << " depth: " << n->depth << std::endl;
}

void print_inorder(Node* x)
{
    if (x == nullptr)
        return;

    print_inorder(x->left);
    print_node(x);
    print_inorder(x->right);
}
