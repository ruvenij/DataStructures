#include <bits/stdc++.h>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

};

void inorderTraversal(Node* root)
{
    if (root == nullptr) return;

    inorderTraversal(root->left);
    std::cout << root->data << " -> ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root)
{
    if (root == nullptr) return;

    std::cout << root->data << " -> ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root)
{
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " -> ";
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    std::cout << "Inorder traversal " << std::endl;
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder traversal " << std::endl;
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal " << std::endl;
    postorderTraversal(root);
    std::cout << std::endl;
    return 0;
}