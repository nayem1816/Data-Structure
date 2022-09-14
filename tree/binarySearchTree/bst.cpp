#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void printTree(treeNode *root, int level);
void spacePrint(int level);

void inOrder(treeNode *root, string &chk)
{
    if (root == NULL)
        return;
    inOrder(root->leftChild, chk);
    chk += (to_string(root->data) + " ");
    inOrder(root->rightChild, chk);
}
void preOrder(treeNode *root, string &chk)
{
    if (root == NULL)
        return;
    chk += to_string(root->data);
    preOrder(root->leftChild, chk);
    preOrder(root->rightChild, chk);
}
void postOrder(treeNode *root, string &chk)
{
    if (root == NULL)
        return;
    postOrder(root->leftChild, chk);
    postOrder(root->rightChild, chk);
    chk += to_string(root->data);
}
int levelOrderTraversal(treeNode *root, string &chk, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int level = 0;
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);
    int max = -9999;

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();
        if (chkNode != NULL)
        {
            if (level == k)
            {
                if (max < chkNode->data)
                {
                    max = chkNode->data;
                }
            }
            cout << chkNode->data << " ";
            chk += to_string(chkNode->data);
            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }

    return max;
}
void printTree(treeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << endl;
        return;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}
void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "   ";
    }
}
void printLeaves(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << " ";
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}
void printLeftNonLeaves(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
    else if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
}
void printRightNonLeaves(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
    else if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
}
void boundaryTraversal(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    // LB Non-Leaves
    printLeftNonLeaves(root->leftChild);
    // LB Leaves
    printLeaves(root->leftChild);
    // RB Leaves
    printLeaves(root->rightChild);
    // RB Non-Leaves
    printRightNonLeaves(root->rightChild);
}

treeNode *insertionBST(treeNode *root, int value)
{
    treeNode *newNode = new treeNode(value);

    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    // value < root->value
    if (value < root->data)
    {
        root->leftChild = insertionBST(root->leftChild, value);
    }
    // value > root->value
    else if (value > root->data)
    {
        root->rightChild = insertionBST(root->rightChild, value);
    }

    return root;
}

treeNode *searchBST(treeNode *root, int value, string &chkPath)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (value == root->data)
    {
        chkPath += (to_string(root->data) + " ");
        return root;
    }
    else if (value < root->data)
    {
        chkPath += (to_string(root->data) + " ");
        searchBST(root->leftChild, value, chkPath);
    }
    else
    {
        chkPath += (to_string(root->data) + " ");
        searchBST(root->rightChild, value, chkPath);
    }

    return NULL;
}

treeNode *inOrderSuccessor(treeNode *root)
{
    treeNode *curr = root;
    while (curr->leftChild != NULL)
    {
        curr = curr->leftChild;
    }
    return curr;
}

treeNode *deleteBST(treeNode *root, int value)
{
    if (value < root->data)
    {
        root->leftChild = deleteBST(root->leftChild, value);
    }
    else if (value > root->data)
    {
        root->rightChild = deleteBST(root->rightChild, value);
    }
    else
    {
        // IMPLEMENT 3 CASES
        if (root->leftChild == NULL)
        {
            // case 1 && case 2
            treeNode *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            // case 2
            treeNode *temp = root->leftChild;
            free(root);
            return temp;
        }
        else
        {
            // case 3
            treeNode *temp = inOrderSuccessor(root->rightChild);
            root->data = temp->data;
            root->rightChild = deleteBST(root->rightChild, temp->data);
        }
        return root;
    }

    return root;
}

int main()
{
    int n;
    cin >> n;
    treeNode *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insertionBST(root, value);
    }

    string traversal = "";
    inOrder(root, traversal);
    cout << "In-order: " << traversal << endl;

    // cout << "Enter the value to be searched: ";
    // int key;
    // cin >> key;
    // string chkPath = "";
    // treeNode *chkNode = searchBST(root, key, chkPath);

    // cout << endl;
    // cout << "Path is : " << chkPath << endl;

    // if (chkNode == NULL)
    // {
    //     cout << endl
    //          << "Value not found" << endl;
    // }
    // else
    // {
    //     cout << endl
    //          << "Value found" << endl;
    // }

    cout << endl;

    int delValue;
    cout << "Enter the value to be deleted: ";
    cin >> delValue;
    root = deleteBST(root, delValue);
    string traversal2 = "";
    inOrder(root, traversal2);
    cout << "After delete In-order: " << traversal2 << endl;

    return 0;
}

/*

Input Formate

Total Node =
9
11 5 9 43 34 1 2 7 21

*/