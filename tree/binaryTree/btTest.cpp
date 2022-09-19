/*
-----MY INPUT FORMATE-----
11
15 11 26
11 8 12
8 6 9
6 -1 -1
9 -1 -1
12 -1 14
14 -1 -1
26 20 30
20 -1 -1
30 -1 35
35 -1 -1


*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;
    Node(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

Node *createTree(int n)
{
    Node *root = new Node(-1);
    if (n == 0)
    {
        return NULL;
    }
    else
    {
        int data;
        cin >> data;
        root->data = data;
        int leftChild, rightChild;
        cin >> leftChild >> rightChild;
        if (leftChild != -1)
        {
            root->leftChild = createTree(leftChild);
        }
        if (rightChild != -1)
        {
            root->rightChild = createTree(rightChild);
        }
        return root;
    }
}

bool isSame(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    return isSame(root1->leftChild, root2->leftChild) && isSame(root1->rightChild, root2->rightChild);
}

void inOrder(Node *root, string &chk)
{
    if (root == NULL)
        return;
    inOrder(root->leftChild, chk);
    chk += (to_string(root->data) + " ");
    inOrder(root->rightChild, chk);
}
void preOrder(Node *root, string &chk)
{
    if (root == NULL)
        return;
    chk += (to_string(root->data) + " ");
    preOrder(root->leftChild, chk);
    preOrder(root->rightChild, chk);
}
void postOrder(Node *root, string &chk)
{
    if (root == NULL)
        return;
    postOrder(root->leftChild, chk);
    postOrder(root->rightChild, chk);
    chk += (to_string(root->data) + " ");
}
int levelOrderTraversal(Node *root, string &chk, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int level = 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int max = -9999;

    while (!q.empty())
    {
        Node *chkNode = q.front();
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
            chk += (to_string(chkNode->data) + " ");
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

int main()
{
    int n1;
    cin >> n1;
    Node *root1 = createTree(n1);

    string inOrderTraversal = "";
    string preOrderTraversal = "";
    string postOrderTraversal = "";
    string lavelordertraversal = "";

    inOrder(root1, inOrderTraversal);
    preOrder(root1, preOrderTraversal);
    postOrder(root1, postOrderTraversal);

    cout << "In-order Traversal: " << inOrderTraversal << endl;
    cout << "Pre-order Traversal: " << preOrderTraversal << endl;
    cout << "Post-order Traversal: " << postOrderTraversal << endl;
    int maxValueAtK = levelOrderTraversal(root1, lavelordertraversal, 2);

    return 0;
}
