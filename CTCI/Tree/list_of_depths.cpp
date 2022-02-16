#include "print_tree.hpp"
#include "trees.hpp"
#include <iostream>
#include <vector>

#define N 20

std::vector<int> v;

struct LinkNode
{
    LinkNode(int key_) : key(key_) {}
    int key;
    LinkNode* next;
};

void push_node(std::vector<LinkNode*>& v, Node* n)
{
    if (n == nullptr)
        return;

    int index = n->depth;

    if (v[index] == nullptr)
    {
        v[index] = new LinkNode(n->key);
    }
    else
    {
        LinkNode* x = v[index];

        while (x->next != nullptr)
        {
            x = x->next;
        }

        x->next = new LinkNode(n->key);
    }
}

void collect_nodes(std::vector<LinkNode*>& v, Node* n)
{
    if (n == nullptr)
        return;

    collect_nodes(v, n->left);
    push_node(v, n);
    collect_nodes(v, n->right);
}

void print_nodes_for_depth(std::vector<LinkNode*>& v, int d)
{
    std::cout << "Depth: " << d << std::endl;

    while (v[d] != nullptr)
    {
        std::cout << v[d]->key << std::endl;
        v[d] = v[d]->next;
    }
}

int main()
{
    Node* root = nullptr;

    for (int i = 1; i < N; i++)
    {
        root = add(root, rand() % 10 * i, 0);
        // root = add(root, i, 0);
    }

    // print_inorder(root);
    draw_tree(root, nullptr, false);

    std::vector<LinkNode*> list(N);

    collect_nodes(list, root);

    for (int i = 0; i < N; i++)
        print_nodes_for_depth(list, i);
}