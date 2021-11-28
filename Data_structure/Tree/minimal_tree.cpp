/* 
    input = [0,1,2,3,4,5,6,7]

                    4
            2              6
        1       3       5       7
    0


*/
#include <vector>
#include <iostream>


class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node* parent_add_;

        Node(int d, Node* parent_add) : data(d), parent_add_(parent_add) {}
};



Node* CreateMinimalSBT(std::vector<int>& input_vector, int start, int end, Node* parent_add)
{
    if (end < start)
        return nullptr;

    int mid = (start + end) / 2;
    Node* n = new Node(input_vector[mid], parent_add);
    n->left = CreateMinimalSBT(input_vector, start, mid - 1, n);
    n->right = CreateMinimalSBT(input_vector, mid + 1, end, n);
    
    return n;
}

Node* CreateMinimalSBT(std::vector<int>& input_vector)
{
    return CreateMinimalSBT(input_vector, 0, input_vector.size() - 1, nullptr);
}

class Tree {
    public:
        Node* head;
        Tree(std::vector<int> input_vector)
        {
            Node* n = CreateMinimalSBT(input_vector);
            if (n->parent_add_ == nullptr)
                head = n;
        }

        void print_tree(Node* n, std::string side)
        {
            if (n == nullptr)
                return;

            if (n->parent_add_ != nullptr)
                std::cout << n->data << " " << side << " of " << n->parent_add_->data << std::endl;
            else 
                std::cout << n->data << " " << side << std::endl;

            print_tree(n->left, "left");
            print_tree(n->right, "right"); 
        }

        void print_tree()
        {
            print_tree(head, "head");
        }
};


int main() 
{
    std::vector<int> input_vector = {0,1,2,3,4,5,6,7,8,9,10};

    // CreateMinimalSBT(input_vector);
    Tree tree = Tree(input_vector);
    tree.print_tree();
}

