#include "trees.hpp"
#include <iostream>
#include <string>
using namespace std;

// Data structure to store a binary tree node
struct Trunk
{
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void show_trunk(Trunk* p)
{
    if (p == nullptr)
    {
        return;
    }

    show_trunk(p->prev);
    cout << p->str;
}

void draw_tree(Node* root, Trunk* prev, bool isLeft)
{
    if (root == nullptr)
    {
        return;
    }

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    draw_tree(root->right, trunk, true);

    if (!prev)
    {
        trunk->str = "———";
    }
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`———";
        prev->str = prev_str;
    }

    show_trunk(trunk);
    cout << " " << root->key << endl;

    if (prev)
    {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    draw_tree(root->left, trunk, false);
}
