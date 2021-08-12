#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
class Node
{
public:
    int Data;
    Node *Right;
    Node *Left;

    Node()
    {

        Right = NULL;
        Left = NULL;
    }
    Node(int userInput)
    {
        Data = userInput;
    }
};
class BinarySearchTree
{
public:
    Node *head;
    void addNewNode(int userInput)
    {
        Node *newNode = new Node(userInput);
        Node *pointer = head;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            valueAddingFunction(newNode, pointer);
        }
    }

    void valueAddingFunction(Node *newNode, Node *pointer)
    {
        if (pointer == NULL)
        {
            pointer = newNode;
        }
        else
        {
            if (pointer->Data > newNode->Data)
            {
                if (pointer->Left == NULL)
                {
                    pointer->Left = newNode;
                }

                else
                {
                    pointer = pointer->Left;
                    valueAddingFunction(newNode, pointer);
                }
            }
            else if (pointer->Data < newNode->Data)
            {
                if (pointer->Right == NULL)
                {
                    pointer->Right = newNode;
                }
                else
                {
                    pointer = pointer->Right;
                    valueAddingFunction(newNode, pointer);
                }
            }
        }
    }

    void inOrderDisplay(Node *pointer)
    {
        if (pointer == NULL)
        {
            return;
        }
        else
        {
            inOrderDisplay(pointer->Left);
            cout << pointer->Data << endl;
            inOrderDisplay(pointer->Right);
        }
    }
    void preOrderDislpay(Node *pointer)
    {
        if (pointer == NULL)
        {
            return;
        }
        else
        {
            cout << pointer->Data << endl;
            preOrderDislpay(pointer->Left);
            preOrderDislpay(pointer->Right);
        }
    }
    void postOrderDisplay(Node *pointer)
    {
        if (pointer == NULL)
        {
            return;
        }
        else
        {
            postOrderDisplay(pointer->Left);
            postOrderDisplay(pointer->Right);
            cout << pointer->Data << endl;
        }
    }

    int minimumNumber(Node *head)
    {
        Node *pointer = head;
        if (pointer->Left == NULL)
        {
            return pointer->Data;
        }
        else
        {
            minimumNumber(pointer->Left);
        }
    }
    int maximumNumber(Node *head)
    {
        Node *pointer = head;

        if (pointer->Right == NULL)
        {
            return pointer->Data;
        }
        else
        {
            maximumNumber(pointer->Right);
        }
    }
    void bfsDislpay(Node *pointer)
    {
        if (pointer == NULL)
            return;
        else
        {
            queue<Node *> que;
            que.push(pointer);
            while (que.empty()== false)
            {
                pointer = que.front();
                cout << pointer->Data << endl;

                if (pointer->Left != NULL)
                {
                    que.push(pointer->Left);
                }
                if (pointer->Right != NULL)
                {
                    que.push(pointer->Right);
                }
                que.pop();
            }
        }
    }
};
int main()
{
    BinarySearchTree *tree = new BinarySearchTree();
    Node *head = new Node();
    int userInput, totalValues, navMenu, loopVar = 1;
    while (loopVar == 1)
    {

        cout << "1. Insertion\n2. In-order Display \n3. Find Minimum\n4. Find Maximum \n5. Pre-Order Display \n6. Post-order Display\n7. BFS-Display\n";
        cin >> navMenu;
        if (navMenu == 1)
        {
            cout << "\n Enter No of Values you want to enter : ";
            cin >> totalValues;
            for (int i = 0; i < totalValues; i++)
            {
                cout << "\n Data " << i + 1 << " : ";
                cin >> userInput;
                tree->addNewNode(userInput);
            }
        }
        else if (navMenu == 2)
        {
            tree->inOrderDisplay(tree->head);
        }
        else if (navMenu == 3)
        {
            cout << "\nMinimum Number : " << tree->minimumNumber(tree->head) << endl;
        }
        else if (navMenu == 4)
        {
            cout << "\nMaximum  Number : " << tree->maximumNumber(tree->head) << endl;
        }
        else if (navMenu == 5)
        {
            tree->preOrderDislpay(tree->head);
        }
        else if (navMenu == 6)
        {
            tree->postOrderDisplay(tree->head);
        }
        else if (navMenu == 7)
        {
            tree->bfsDislpay(tree->head);
        }
        else
            break;
    }
    return 0;
}