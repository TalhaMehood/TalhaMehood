#include <iostream>
#include <stdio.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int userInput)
    {
        data = userInput;
    }
};

class DoublyList
{
    Node *head;

public:
    DoublyList()
    {
        head = NULL;
    }
    DoublyList(Node *n)
    {
        head = n;
    }
    void addAtStart(int userInput)
    {
        Node *newNode = new Node(userInput);
        newNode->prev = NULL;
        newNode->next = head;
        head = newNode;
    }
    void printList()
    {
        if (head == NULL)
        {
            cout << "\n List Is Empty.. \n";
        }
        else
        {
            Node *ptr = head;
            while (ptr != NULL)
            {
                cout << ptr->data << "<->";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
    void addAtEnd(int userInput)
    {
        Node *lastNode = new Node(userInput);

        if (head == NULL)
        {
            head = lastNode;
        }
        else
        {
            Node *pointer = head;
            while (pointer->next != NULL)
            {
                pointer = pointer->next;
            }
            pointer->next = lastNode;
            lastNode->next = NULL;
            lastNode->prev = pointer;
        }
    }
    void addAtPosition(int position, int userInput)
    {
        Node *pointer = head;
        Node *newNode = new Node(userInput);
        if (position == 1)
        {
            newNode->next = head;
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {
            while (position != 2)
            {
                pointer = pointer->next;
                position--;
            }
            newNode->next = pointer->next;
            pointer->next = newNode;
        }
        printList();
    }
    void deleteFirstNode()
    {
        head = head->next;
        head->prev = NULL;
    }
    void deleteLastNode()
    {
        Node *pointer = head;
        while (pointer->next->next != NULL)
        {
            pointer = pointer->next;
            cout << "Ran \n";
        }
        pointer->next = NULL;
    }
    void deleteSpecificNode(int nodeToDel)
    {
        Node *pointer = head;
        if (nodeToDel == 1)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            while (nodeToDel != 2)
            {
                pointer = pointer->next;
                nodeToDel--;
            }
            pointer->next = pointer->next->next;
        }
        
    }
    void updateNodeValue(int nodeNo, int updatedValue)
    {
        Node *pointer=head;

        if(nodeNo == 1)
        {
            head->data=updatedValue;
        }
        else
        {
            while(nodeNo != 1)
            {
                pointer=pointer->next;
                nodeNo--;
            }

            pointer->data=updatedValue;
        }
        printList();
    }
};

int main()
{
    DoublyList *list = new DoublyList();
    int navMenu, loopVariable = 1;
    while (loopVariable = !0)
    {
        // cout << "\n Please Enter Your Number : ";
        // cin >> newNode->data;
        cout << "Menu: \n 1) Insertion at Start\n 2) Intertion at End\n 3) Printing List\n 4) Add Node at Specified Position\n 5) Delete Node\n 6) Update Value\n 00) Exit " << endl;
        cin >> navMenu;
        if (navMenu == 1)
        {
            cout << "Enter No. of Nodes to be added at start " << endl;
            int nodesAtStart;
            cin >> nodesAtStart;
            for (int i = 0; i < nodesAtStart; i++)
            {
                int userInput;
                cout << "Enter the Value for the " << i + 1 << " Node : " << endl;
                cin >> userInput;
                list->addAtStart(userInput);
                cout << endl;
                cout << "\n Your Updated List :" << endl;
                list->printList();
            }
        }
        else if (navMenu == 2)
        {
            cout << "Enter No. of Nodes to be added at End " << endl;
            int nodesAtStart;
            cin >> nodesAtStart;
            int userInput;
            for (int i = 0; i < nodesAtStart; i++)
            {
                cout << "Enter the Value to add at end: ";
                cin >> userInput;
                list->addAtEnd(userInput);
                cout << endl;
                cout << "\n Your Updated List :" << endl;
                list->printList();
            }
        }
        else if (navMenu == 3)
        {
            list->printList();
        }
        else if (navMenu == 4)
        {
            int position, userInput;
            cout << "\nPosition to Add a Node at :";
            cin >> position;
            cout << "\nEnter The Value to be added :";
            cin >> userInput;
            list->addAtPosition(position, userInput);
        }
        else if (navMenu == 5)
        {
            int prompt;
            cout << "\t1) First Node.\n\t2) Last Node.\n\t3) Specific Node \t" << endl;
            cin >> prompt;
            switch (prompt)
            {
            case 1:
                list->deleteFirstNode();
                cout << "\nUpdated List :" << endl;
                list->printList();
                break;
            case 2:
                list->deleteLastNode();
                cout << "\nUpdated List :" << endl;
                list->printList();

                break;
            case 3:
                int nodeToDel;
                cout << "Please Enter the Node No. : ";
                cin >> nodeToDel;
                list->deleteSpecificNode(nodeToDel);
                cout << "\nUpdated List :" << endl;
                list->printList();

                break;
            default:
                cout << "Please Enter A Valid Option ";
                break;
            }
        }
        else if(navMenu==6)
        {   int updatedValue, nodeNo;
            cout<<"Enter The Node no: ";
            cin>>nodeNo;
            cout<<"Enter the Updated Value: ";
            cin>>updatedValue;
            list->updateNodeValue(nodeNo, updatedValue);

        }
        else if (navMenu == 00)
        {
            break;
        }
        else
        {
            cout << "\nPlease Enter a Valid option.. " << endl;
        }
    }
}