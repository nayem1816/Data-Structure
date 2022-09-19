#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *prev;
    doublyNode *next;
    doublyNode(int val)
    {
        this->value = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

int countOfDoublyNodes(doublyNode *&head)
{
    int count = 0;
    doublyNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(doublyNode *&head)
{
    doublyNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->next != NULL)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void reverseDoublyList(doublyNode *&head)
{

    doublyNode *temp = head;
    doublyNode *prev = NULL;
    doublyNode *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }
    head = prev;
}

void insertAtHead(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main()
{
    doublyNode *head = NULL;

    int value, position, searchValue;
    cout << "Choice-1: Count the number of Nodes in the doubly linked list" << endl;
    cout << "Choice-2: Display in the doubly linked list" << endl;
    cout << "Choice-3: Reverse doubly linked list" << endl;
    cout << "Choice-4: Insert at head" << endl;
    cout << "Choice-5: Insert at tail" << endl;

    cout << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Number of Nodes in the doubly linked list: " << countOfDoublyNodes(head) << endl;
            break;
        case 2:
            cout << "Display in the doubly linked list: ";
            display(head);
            break;

        case 3:
            reverseDoublyList(head);
            break;

        case 4:
            cout << "Enter the value : ";
            cin >> value;
            insertAtHead(head, value);
            // cout << "Display in the doubly linked list insert at head: ";
            // display(head);
            break;

        case 5:
            cout << "Enter the value : ";
            cin >> value;
            insertAtTail(head, value);
            // cout << "Display in the doubly linked list insert at tail: ";
            // display(head);
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