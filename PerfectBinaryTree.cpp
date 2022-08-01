#include <bits/stdc++.h>

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    int value = -1;

    Node(int value)
    {
        this->value = value;
    }
};

int findDepth(Node* root)
{
    if (root == nullptr) return 0;

    int depth = 0;
    while(root != nullptr)
    {
        depth++;
        root = root->left;
    }

    return depth;
}

bool isPerfect(Node* node, int depth, int level)
{
    if ((node->left == nullptr) and (node->right == nullptr))
        return (depth == (level + 1));
    
    if ((node->left == nullptr) or (node->right == nullptr))
        return false;

    return (isPerfect(node->left, depth, level + 1) and isPerfect(node->right, depth, level + 1));
}

bool isPerfectTree(Node* root)
{
    if (root == nullptr) return true;

    int depth = findDepth(root);

    return isPerfect(root, depth, 0);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    std::cout << isPerfectTree(root) << std::endl;

    return 0;
}