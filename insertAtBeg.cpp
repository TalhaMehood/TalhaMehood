#include <iostream>
#include <stdio.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void addAtBeg(int x);
    void printList();
};
Node *head;
void Node ::addAtBeg(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    printList(head);
}
void Node ::printList()
{
    Node *ptr;
    ptr = head;

    while (ptr != NULL)

    {
        cout << "The List is :";
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    Node List;
    head = NULL;
    // Node *first = NULL;
    // Node *second = NULL;
    // Node *third = NULL;
    // Node *fourth = new Node();
    // Node *fifth = new Node();

    // first = new Node();
    // second = new Node();
    // third = new Node();

    // first->data=8;
    // second->data=9;
    // third->data=10;
    // fourth->data=11;
    // fifth->data=12;

    // first->next=second;
    // second->next=third;
    // third->next=fourth;
    // fourth->next=fifth;
    // fifth->next=NULL;

    cout << "Enter the number of item : ";
    int x, i = 0, y;
    cin >> x;

    while (i < x)
    {

        cout << "Please Enter the data Item : " << endl;
        cin >> y;
        List.addAtBeg(y);
        i++;
    }

    List.printList();
}
