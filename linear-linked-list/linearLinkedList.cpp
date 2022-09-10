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

struct Test
{
    int position[1000];
};

int countOfNodes(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(Node *&head)
{
    Node *temp = head;
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

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtSpecificPosition(Node *&head, int value, int position)
{
    if (position == 0)
    {
        insertAtHead(head, value);
        return;
    }
    Node *newNode = new Node(value);
    Node *temp = head;
    int count = 0;
    while (temp->next != NULL && count < position - 2)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (temp->next == NULL)
    {
        return -1;
    }
    while (temp->value != key)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        temp = temp->next;
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countOfNodes(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->next;
        count++;
    }
    if (flag == 0)
    {
        cout << "The search value not in the list" << endl;
    }
    else
    {
        position[0] = k;
        cout << "The search value is found at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i != position[0] - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void insertAfterValueUnique(Node *&head, int searchValue, int value)
{
    int position;
    position = searchByValueUnique(head, searchValue);

    insertAtSpecificPosition(head, value, position + 1);
}

// Test insertAfterValueDuplicate(Node *&head, int searchValue, int value)
// {
//     Test T;
//     T = searchByValueDuplicateReturn(head, searchValue);
//     for (int i = 1; i < T.position[0]; i++)
//     {
//         insertAtSpecificPosition(head, value, T.position[i] + 1);
//     }
//     return T;
// }

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(Node *&head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = NULL;
    delete temp2;
}

void deleteAtSpecificPosition(Node *&head, int position)
{
    if (position == 0)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    int count = 0;
    while (temp->next != NULL && count < position - 2)
    {
        temp = temp->next;
        count++;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

void deleteByValueUnique(Node *&head, int value)
{
    int position;
    position = searchByValueUnique(head, value);
    if (position == -1)
    {
        cout << "The search value not in the list" << endl;
        return;
    }
    deleteAtSpecificPosition(head, position);
}

// void deleteByValueDuplicate(Node *&head, int value)
// {
//     Test T;
//     T = searchByValueDuplicateReturn(head, value);
//     for (int i = 1; i < T.position[0]; i++)
//     {
//         deleteAtSpecificPosition(head, T.position[i]);
//     }
// }

Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "The Linked list is empty" << endl;
        return head;
    }
    Node *next = head->next;

    while (true)
    {
        current->next = prev;
        prev = current;
        current = next;
        if (next == NULL)
        {
            break;
        }
        next = next->next;
    }
    return prev;
}

Node *reverseRecursive(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        if (head == NULL)
        {
            cout << "The Linked list is empty" << endl;
        }
        return head;
    }

    Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int findMid(Node *head)
{
    if (head == NULL)
    {
        return -1;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}

void makeCycle(Node *head, int position)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == position)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow->next == fast->next)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // step:1
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // step:2
    fast = head;

    // step:3
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // step:4
    slow->next = NULL;
}

int main()
{
    Node *head = NULL;

    int value, position, searchValue;
    cout << "Choice-1: Count the number of nodes in the linked list" << endl;
    cout << "Choice-2: Display in the linked list" << endl;
    cout << "Choice-3: Insert at head" << endl;
    cout << "Choice-4: Insert at tail" << endl;
    cout << "Choice-5: Insert at specific position" << endl;
    cout << "Choice-6: Search a value ( Unique list )" << endl;
    cout << "Choice-7: Search a value ( Duplicate enable list )" << endl;
    cout << "Choice-8: Insert after a specific value ( Unique List )" << endl;
    cout << "Choice-9: Insert after a specific value ( Duplicate enable list )" << endl;
    cout << "Choice-10: Delate at head" << endl;
    cout << "Choice-11: Delete at tail" << endl;
    cout << "Choice-12: Delete at specific position" << endl;
    cout << "Choice-13: Delete a specific value ( Unique list )" << endl;
    cout << "Choice-14: Delete a specific value ( Duplicate enable list )" << endl;
    cout << "Choice-15: Reverse the linked list ( Non Recursive )" << endl;
    cout << "Choice-16: Reverse the linked list ( Recursive )" << endl;
    cout << "Choice-17: Mid value in this linked list" << endl;
    cout << "Choice-18: Create Cycle in this linked list" << endl;
    cout << "Choice-19: Detect Cycle in this linked list" << endl;
    cout << "Choice-20: Remove Cycle in this linked list" << endl;
    cout << "Choice-0: Exit" << endl
         << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Number of nodes in the linked list: " << countOfNodes(head) << endl;
            break;
        case 2:
            cout << "Display in the linked list: ";
            display(head);
            break;

        case 3:
            cout << "Enter the value : ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 4:
            cout << "Enter the value : ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 5:
            cout << "Enter the position : ";
            cin >> position;
            cout << "Enter the value : ";
            cin >> value;
            insertAtSpecificPosition(head, value, position);
            break;

        case 6:
            cout << "Enter the value you search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position != -1)
            {
                cout << "Value found at position: " << position << endl;
            }
            else
            {
                cout << "Value not found" << endl;
            }
            break;

        case 7:
            cout << "Enter the search value: ";
            cin >> value;
            // searchByValueDuplicate(head, value);
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.position[0] == 0)
            {
                cout << "The searched value is not yet in the list" << endl;
            }
            else
            {
                cout << "Value found at position: ";
                for (int i = 1; i < T.position[0]; i++)
                {
                    cout << T.position[i];
                    if (i != T.position[0] - 1)
                    {
                        cout << ", ";
                    }
                }
                cout << endl;
            }
            break;

        case 8:
            cout << "Enter the search value : ";
            cin >> searchValue;
            cout << "Enter the to insert : ";
            cin >> value;
            insertAfterValueUnique(head, searchValue, value);
            break;

            // case 9:
            //     cout << "Enter the search value : ";
            //     cin >> searchValue;
            //     cout << "Enter the to insert : ";
            //     cin >> value;
            //     Test T1;
            //     T1 = insertAfterValueDuplicate(head, searchValue, value);
            //     if (T1.position[0] == 0)
            //     {
            //         cout << "The searched value is not yet in the list" << endl;
            //     }
            //     else
            //     {
            //         cout << "Value found at position: ";
            //         for (int i = 1; i < T1.position[0]; i++)
            //         {
            //             cout << T1.position[i];
            //             if (i != T1.position[0] - 1)
            //             {
            //                 cout << ", ";
            //             }
            //         }
            //         cout << endl;
            //     }
            //     break;

        case 10:
            deleteAtHead(head);
            break;

        case 11:
            deleteAtTail(head);
            break;

        case 12:
            cout << "Enter the position : ";
            cin >> position;
            deleteAtSpecificPosition(head, position);
            break;

        case 13:
            cout << "Enter the value : ";
            cin >> value;
            deleteByValueUnique(head, value);
            break;

            // case 14:
            //     cout << "Enter the value : ";
            //     cin >> value;
            //     deleteByValueDuplicate(head, value);
            //     break;

        case 15:
            head = reverseNonRecursive(head);
            break;
        case 16:
            head = reverseRecursive(head);
            break;

        case 17:
            int mid;
            mid = findMid(head);
            if (mid == -1)
            {
                cout << "The Linked List is empty" << endl;
            }
            else
            {
                cout << "The Mid value of linked list is: " << mid << endl;
            }
            break;

        case 18:
            cout << "Enter the position to create cycle: ";
            cin >> position;
            makeCycle(head, position);
            break;

        case 19:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if (cycleStatus == true)
            {
                cout << "There is a Cycle in the list" << endl;
            }
            else
            {
                cout << "There is NO Cycle in the list" << endl;
            }
            break;

        case 20:
            cycleStatus = detectCycle(head);
            if (cycleStatus == true)
            {
                removeCycle(head);
            }
            else
            {
                cout << "There is NO Cycle in the list" << endl;
            }
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