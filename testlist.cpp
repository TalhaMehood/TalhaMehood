#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next; // to point at the object of the same class
    void addAtBeg( int x);
    void listTrav(Node *ptr);
    void addAtEnd(Node *head);
    void addAtPos(Node *head);
    void deleteAtBeg(Node *head);
    void deleteAtEnd(Node *head);
    void searchNode(Node *head);
};

Node *head = NULL;
void Node ::searchNode(Node *head)
{
    Node *ptr = head;
    int x;
    cout << "Please Enter the Data you want To search : ";
    cin >> x;

    while (ptr != NULL)
    {
        if (ptr->data == x)
        {
            cout << "\n\t ***Value is Present in the linked list***" << endl;
            break;
        }
        else if (ptr->next == NULL)
        {
            cout << "\n\t ***Value Not Present in The List***" << endl;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
}
void Node ::addAtBeg( int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    listTrav(head);
}
void Node ::deleteAtEnd(Node *ptr)
{
    ptr = head;
    Node *ptr2 = head;

    if (head->next == NULL)
    {
        cout << "List is Empty.. ";
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        while (ptr2->next != ptr)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next = NULL;
        listTrav(head);
    }
}

void Node ::deleteAtBeg(Node *ptr)
{
    ptr = head;
    if (head == NULL)
    {
        cout << "List is Empty.. ";
    }
    else
    {
        cout << "Deleting.. ";
        head = head->next;
        free(ptr);
        cout << "Updated LinkedList : " << endl;
        listTrav(head);
    }
}
void Node ::listTrav(Node *ptr)
{

    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
// void Node::createNode(Node *head)
// {
//     Node *temp = new Node();
//     Node *ptr = head;
//     cout << "Please Enter data for the first Node: " << endl;
//     cin >> temp->data;
//     if (ptr->next == NULL)
//     {
//         temp = head;
//     }
//     else
//     {
//         temp->next = head;
//         temp = head;
//     }
// }

void Node ::addAtPos(Node *head)
{
    Node *newNode = NULL;
    newNode = new Node();
    Node *ptr = head;

    int pos;
    cout << "\n Please Enter Your Specified Position : ";
    cin >> pos;
    if (pos == 1)
    {
        cout << "\n Please Enter Your Number : ";
        cin >> newNode->data;
        newNode->next = ptr;
        head = newNode;
    }
    else
    {

        pos--;
        cout << "\n Please Enter Your Number : ";
        cin >> newNode->data;
        while (pos != 1)
        {
            pos--;
            ptr = ptr->next;
        }

        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    listTrav(head);
}
void Node ::addAtEnd(Node *head)
{
    Node *newNode = NULL;
    newNode = new Node();
    Node *ptr = head;

    cout << "Please Add Your Number To The End of LinkedList: ";
    cin >> newNode->data;

    newNode->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->next = NULL;
    cout << "\n Added Successfully and your output is: " << endl;
    listTrav(head);
}
int secondF(Node *second, Node *last)
{
    second->data = 12;
    second->next = last;
}

int main()
{
    head = NULL;
    int x;
    char c = 'y';
    Node list;
    // Node* head=NULL; //Declared Globally
    Node *first = new Node();
    Node *second = new Node();
    Node *last = new Node();

    first->data = 8;
    first->next = second;

    secondF(second, last);

    last->data = 28;
    last->next = NULL;

    head = first;
    cout << "\nCurrent List :" << endl;
    list.listTrav(head);

jump:
    while (c == 'Y' || c == 'y')
    {
        ////////////////////////////ADDING NEW NODE//////////////////////////////////////
        cout << "Enter 1 to add a node at the START of the Linked List \nEnter 2 to add at the END of the Linked List \nEnter 3 To Print The LinkedList \nEnter 4 To Add Node At Specific Position \nEnter 5 to Search For Data \nEnter 6 To delete the First Node\nEnter 7 to delete the Last Node: " << endl;
        cin >> x;

        if (x == 1)
        {
            while (x == 1)
            {   int y;
                cout << "Please Enter the Number to add to your Linked List :";
                cin >> y;
                list.addAtBeg(y);
                cout << "\n Do you wish to Quit? Enter 00 to quit \n To add node at Begining Enter 1" << endl;
                cin >> x;
                if (x == 00)
                {
                    break;
                }
            }
        }
        else if (x == 2)
        {
            while (x == 2)
            {
                list.addAtEnd(head);
                cout << "\n Do you wish to Quit? Enter 00 to quit \n To add node at end Enter 2 " << endl;
                cin >> x;
                if (x == 00)
                {
                    break;
                }
            }
        }

        else if (x == 3)
        {
            list.listTrav(head);
        }
        else if (x == 4)
        {
            while (x == 4)
            {
                list.addAtPos(head);
                cout << "\n Do you wish to Quit? Enter 00 to quit \n To add node at Specific Position Enter 4" << endl;
                cin >> x;
                if (x == 00)
                {
                    break;
                }
            }
        }

        else if (x == 5)
        {
            while (x == 5)
            {
                list.searchNode(head);
                cout << "\n Do you wish to Quit? Enter 00 to quit \n To Search for more Values Press 5" << endl;
                cin >> x;
                if (x == 00)
                {
                    break;
                }
            }
        }

        else if (x == 6)
        {
            while (x == 6)
            {
                list.deleteAtBeg(head);
                cout << "\n Do you wish to Quit? Enter 00 to quit \n To Delete First Node Press 6" << endl;
                cin >> x;
                if (x == 00)
                {
                    break;
                }
            }
        }
        else if (x == 7)
        {
            while (x == 7)
            {
                list.deleteAtEnd(head);
                cout << "\n Do you wish to Quit? Enter 00 to quit \n To Delete First Node Press 7" << endl;
                cin >> x;
                if (x == 00)
                {
                    break;
                }
            }
        }
        else if (x != 1 || x != 2 || x != 00)
        {
            cout << " \nWrong Number inserted or Format did not matched..." << endl;
        }
        else if (x == 00)
        {
            break;
        }

        cout << " \nDo you Wish to Quit the LinkedList? Y/N :" << endl;
        cin >> c;

        if (c == 'y' || c == 'Y')
        {
            cout << "\nYou are out of Linked List" << endl;
            break;
        }
        else if (c == 'n' || c == 'N')
        {
            //    continue;
            c = 'y';
            goto jump;
        }
    }

    return 0;
}