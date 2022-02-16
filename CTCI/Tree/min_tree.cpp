
#include "print_tree.hpp"
#include "trees.hpp"
#include <iostream>
#include <vector>

#define N 50

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
}