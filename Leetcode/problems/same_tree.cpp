#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr)
    {
        std::cout << "Both null ptr\n";
        return true;
    }

    if (p == nullptr || q == nullptr)
    {
        std::cout << "One null ptr\n";
        return false;
    }

    if (p->val != q->val)
    {
        std::cout << "Different values " << p->val << " and " << q->val << std::endl;
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    TreeNode* p = new TreeNode(1);
    TreeNode* q = new TreeNode(1);

    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    std::cout << isSameTree(q, p) << std::endl;
}