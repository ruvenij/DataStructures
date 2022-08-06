#include <bits/stdc++.h>

struct Node
{
    int data = -1;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int value)
    {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void printTree(Node* root)
{
    if (root == nullptr) return;

    printTree(root->left);
    
    std::cout << root->data << " -> ";
    
    printTree(root->right);
}

void insertNode(Node* root, int value)
{
    if (root == nullptr) 
    {
        root = new Node(value);
        return;
    }

    if (value < root->data)
    {
        if (root->left == nullptr)
        {   
            root->left = new Node(value);
            return;
        }
        
        insertNode(root->left, value);
    }

    if (value > root->data)
    {
        if (root->right == nullptr)
        {   
            root->right = new Node(value);
            return;
        }
        
        insertNode(root->right, value);
    }
}

int getMinValueNode(Node* node)
{
    Node* currentNode = node;

    if (currentNode == nullptr) return -1;

    while (currentNode->left != nullptr)
    {
        currentNode = currentNode->left;
    }

    return currentNode->data; 
}

void deleteNode(Node* node, int value, Node* currentRoot)
{
    if (node == nullptr) 
        return;

    if (node->data == value)
    {
        if ((node->left == nullptr) and (node->right == nullptr))
        {
            if (currentRoot->left == node)
                currentRoot->left = nullptr;

            if (currentRoot->right == node)
                currentRoot->right = nullptr;

            delete node;
        }
        else if (node->left == nullptr)
        {
            if (currentRoot->left == node)
                currentRoot->left = node->right;

            if (currentRoot->right == node)
                currentRoot->right = node->right;

            delete node;
        }
        else if (node->right == nullptr)
        {
            if (currentRoot->left == node)
                currentRoot->left = node->left;

            if (currentRoot->right == node)
                currentRoot->right = node->left;

            delete node;
        }
        else
        {
            int val = getMinValueNode(node->right);
            deleteNode(node->right, val, node);
            node->data = val;
        }

        return;
    }    

    if (value < node->data)
        deleteNode(node->left, value, node);

    if (value > node->data)
        deleteNode(node->right, value, node);
}

Node* search(Node* root, int value)
{
    if (root == nullptr) 
        return nullptr;

    if (root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);

    if (value > root->data)
        return search(root->right, value);

    return nullptr;
}

int main()
{
    Node* root = new Node(8);
    insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 10);
    insertNode(root, 14);
    insertNode(root, 4);

    printTree(root);
    std::cout << std::endl;

    deleteNode(root, 3, nullptr);
    printTree(root);
    std::cout << std::endl;

    return 0;
}