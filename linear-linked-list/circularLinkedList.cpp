#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        this->value = val;
        this->next = NULL;
    }
};

int countOfNodes(Node *&head)
{
    Node *temp = head;
    int count = 0;

    if (head == NULL)
    {
        return 0;
    }

    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

void display(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }
    do
    {
        cout << temp->value;
        temp = temp->next;
        if (temp != head)
        {
            cout << " -> ";
        }
    } while (temp != head);
    cout << endl;
}

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    head = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
}

void delateHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        Node *delNode = temp;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = delNode->next;
        head = delNode->next;
        delete delNode;
    }
    else
    {
        cout << "The linked list empty" << endl;
    }
}

void delateTail(Node *&head)
{
    Node *temp = head;

    if (temp != NULL && temp->next != head)
    {
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
        {
            cout << "The liked list is empty" << endl;
        }
        else
        {
            delateHead(head);
        }
    }
}

int main()
{
    Node *head = NULL;

    int value, position, searchValue;
    cout << "Choice-1: Count the number of Nodes in the linked list" << endl;
    cout << "Choice-2: Display in the linked list" << endl;
    cout << "Choice-3: Reverse linked list" << endl;
    cout << "Choice-4: Insert at head" << endl;
    cout << "Choice-5: Insert at tail" << endl;
    cout << "Choice-6: Delate at head" << endl;
    cout << "Choice-7: Delate at tail" << endl;

    cout << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Number of Nodes in the linked list: " << countOfNodes(head) << endl;
            break;
        case 2:
            display(head);
            break;

        case 3:
            cout << "Display in the linked list reverse: ";
            // displayReverse(head);
            break;

        case 4:
            cout << "Enter the value : ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 5:
            cout << "Enter the value : ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 6:
            delateHead(head);
            break;

        case 7:
            delateTail(head);
            break;

        default:
            break;
        }
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }

    return 0;
}