#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int left, int right)
{
    return (left > right) ? left : right;
}

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *node)
{
    Node *pointer = node->left;
    Node *T2 = pointer->right;

    // Perform rotation
    pointer->right = node;
    node->left = T2;

    // Update heights
    node->height = max(height(node->left), height(node->right)) + 1;
    pointer->height = max(height(pointer->left), height(pointer->right)) + 1;

    // Return new head
    return pointer;
}

Node *leftRotate(Node *node)
{
    Node *pointer = node->right;
    Node *T2 = pointer->left;

    // Perform rotation
    pointer->left = node;
    node->right = T2;

    // Update heights
    node->height = max(height(node->left), height(node->right)) + 1;
    pointer->height = max(height(pointer->left), height(pointer->right)) + 1;

    // Return new head
    return pointer;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *head, int data)
{

    if (head == NULL)
        return head;

    if (data < head->data)
        head->left = deleteNode(head->left, data);

    else if (data > head->data)
        head->right = deleteNode(head->right, data);

    else
    {
        // node with only one child or no child
        if ((head->left == NULL) || (head->right == NULL))
        {
            Node *temp;
            if (head->left != NULL)
                temp = head->left;
            else
                temp = head->right;

            if (temp == NULL)
            {
                temp = head;
                head = NULL;
            }
            else
                *head = *temp; // One child caseCopy the contents of the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node *temp = minValueNode(head->right);

            // Copy the inorder successor's
            // data to this node
            head->data = temp->data;

            // Delete the inorder successor
            head->right = deleteNode(head->right, temp->data);
        }
    }

    // If the tree had only one node
    // then return
    if (head == NULL)
        return head;

    head->height = 1 + max(height(head->left), height(head->right));

    int balance = getBalance(head);

    // Left Left Case
    if (balance > 1 && getBalance(head->left) >= 0)
        return rightRotate(head);

    // Left Right Case
    if (balance > 1 &&
        getBalance(head->left) < 0)
    {
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }

    // Right Right Case
    if (balance < -1 && getBalance(head->right) <= 0)
        return leftRotate(head);

    // Right Left Case
    if (balance < -1 &&
        getBalance(head->right) > 0)
    {
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }

    return head;
}

void preOrder(Node *head)
{
    if (head != NULL)
    {
        cout << head->data << " ";
        preOrder(head->left);
        preOrder(head->right);
    }
}

int main()
{
    Node *head = NULL;

    head = insert(head, 40);
    head = insert(head, 50);
    head = insert(head, 60);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 15);

    cout << "Preorder traversal of this AVL tree is \n";
    preOrder(head);
    cout << "\n\n";
    head = deleteNode(head, 30);
    preOrder(head);

    return 0;
}