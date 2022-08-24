#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

void insertAtBottom(Stack<int> &chk, int chkElement)
{
    if (chk.empty())
    {
        chk.push(chkElement);
        return;
    }

    int topElement = chk.Top();
    chk.pop();
    insertAtBottom(chk, chkElement);

    chk.push(topElement);
}

void reverseStack(Stack<int> &st)
{

    if (st.empty())
    {
        cout << "Stack is empty" << endl;
        return;
    }

    int topElement = st.Top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}

int main()
{
    Stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while (!st.empty())
    {
        cout << st.Top() << " ";
        st.pop();
    }

    return 0;
}