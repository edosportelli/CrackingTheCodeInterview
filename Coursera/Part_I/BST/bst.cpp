#include <iostream>
#include <queue>
#include <random>
#include <string>

#define N 10

struct Node
{
    Node(int key_, std::string value_) : key(key_), value(value_) {}

    int key;
    std::string value;
    Node* left = nullptr;
    Node* right = nullptr;
    uint16_t count{1};
};

uint16_t get_count(Node* n)
{
    if (n == nullptr)
        return 0;

    return n->count;
}

Node* root;

Node* add(Node* x, int key, std::string value)
{
    if (x == nullptr)
    {
        std::cout << "Creating node " << key << std::endl;
        return new Node(key, value);
    }

    if (key < x->key)
    {
        std::cout << key << " less than " << x->key << std::endl;
        x->left = add(x->left, key, value);
    }
    else if (key > x->key)
    {
        std::cout << key << " greater than " << x->key << std::endl;
        x->right = add(x->right, key, value);
    }
    else
    {
        std::cout << key << " ---- already exists!\n";
        x->value = value;
    }

    x->count = 1 + get_count(x->right) + get_count(x->left);

    return x;
}

void inorder(std::queue<int>& queue, Node* x)
{
    if (x == nullptr)
        return;

    inorder(queue, x->left);
    queue.push(x->key);
    inorder(queue, x->right);
}

// Rank: how many elements before k
int rank(Node* x, int key)
{
    if (x == nullptr)
        return 0;

    if (x->key == key)
        return get_count(x->left);
    else if (x->key > key)
        return rank(x->left, key);
    else
        return rank(x->right, key) + get_count(x->left) + 1;
}

int rank(int key)
{
    return rank(root, key);
}

void add(int key, std::string value)
{
    root = add(root, key, value);
}

void print(Node* n)
{
    std::cout << "Key: " << n->key << " counter: " << n->count << std::endl;
}

void print_tree(Node* n)
{
    print(n);
    if (n->left != nullptr)
        print_tree(n->left);
    if (n->right != nullptr)
        print_tree(n->right);
}

void print_inorder(Node* x)
{
    if (x == nullptr)
        return;

    print_inorder(x->left);
    print(x);
    print_inorder(x->right);
}

int main()
{
    // root = new Node(6, "root");
    for (int i = 0; i < N; i++)
        // add(i, std::to_string(i));
        add(rand() % 10, std::to_string(i));

    print_tree(root);

    std::cout << rank(1) << std::endl;

    std::queue<int> queue;
    inorder(queue, root);

    while (queue.size() > 0)
    {
        std::cout << queue.front() << std::endl;
        queue.pop();
    }

    print_inorder(root);
}