#include "print_tree.hpp"
#include "trees.hpp"
#include <vector>

#define N 20

Node* delete_min(Node* n)
{
    if (n->left == nullptr)
        return n->right;

    n->left = delete_min(n->left);

    return n;
}

Node* delete_max(Node* n)
{
    if (n->right == nullptr)
        return n->left;

    n->right = delete_max(n->right);

    return n;
}

Node* find_key(Node* n, int key)
{
    if (n == nullptr)
    {
        std::cout << "key not present!\n";
        return nullptr;
    }

    if (key == n->key)
        return n;
    else if (key < n->key)
        return find_key(n->left, key);
    else
        return find_key(n->right, key);
}

Node* find_min(Node* n)
{
    if (n->left == nullptr)
        return n;

    return find_min(n->left);
}

Node* delete_node(Node* root, int key)
{
    Node* n = find_key(root, key);

    if (n->left == nullptr)
        return n->right;
    else if (n->right == nullptr)
        return n->left;

    Node* min = find_min(n->right);

    n->key = min->key;
    n->right = delete_min(n->right);

    return n;
}

std::vector<int> v;

Node* create_min_tree(Node* n, int l, int r)
{
    if (r <= l)
        return nullptr;

    int mid = l + (r - l) / 2;
    n = add(n, v[mid], 0);

    create_min_tree(n, l, mid);
    create_min_tree(n, mid + 1, r);

    return n;
}

int main()
{
    Node* root = nullptr;

    for (int i = 0; i < N; i++)
        v.push_back(i);

    root = create_min_tree(root, 0, N);

    draw_tree(root, nullptr, false);

    delete_node(root, 18);
    delete_node(root, 13);
    delete_node(root, 5);
    delete_node(root, 15);

    draw_tree(root, nullptr, false);
}