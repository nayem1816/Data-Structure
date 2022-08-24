#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

void reverseSentence(string str)
{
    Stack<string> st;
    for (int i = 0; i < str.length(); i++)
    {
        string word = "";
        while (str[i] != ' ' && i < str.length())
        {
            word += str[i];
            i++;
        }
        st.push(word);
    }

    while (!st.empty())
    {
        cout << st.pop() << " ";
    }
}

int main()
{
    string str = "I am Nayem";
    reverseSentence(str);

    return 0;
}