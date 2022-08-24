#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

int globalID = 100;

class person
{
    string name;
    int id;
    float salary;

public:
    person()
    {
        this->name = "";
        this->id = -1;
        this->salary = -1.0;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    person(string name, float salary)
    {
        setName(name);
        setSalary(salary);
        this->id = globalID;
        globalID++;
    }

    int getID()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    float getSalary()
    {
        return this->salary;
    }
    void print()
    {
        cout << "Name: " << this->name << endl;
        cout << "ID: " << this->id << endl;
        cout << "Salary: " << this->salary << endl;
        cout << endl;
    }
};

int main()
{
    // Stack<pair<int, char>> st;

    // st.push(make_pair(1, 'a'));
    // st.push(make_pair(2, 'b'));
    // st.push(make_pair(3, 'c'));

    // while (!st.empty())
    // {
    //     pair<int, char> chk;
    //     chk = st.pop();
    //     cout << chk.first << " | " << chk.second << endl;
    //     // cout << st.pop() << endl;
    // }

    // cout << st.size() << endl;
    // if (!st.empty())
    // {
    //     pair<int, char> chk;
    //     chk = st.Top();
    //     cout << chk.first << " | " << chk.second << endl;
    //     // cout << st.Top() << endl;
    // }

    Stack<person> st;
    person p1("John", 10000);
    person p2("Jane", 20000);
    person p3("Jack", 30000);

    st.push(p1);
    st.push(p2);
    st.push(p3);

    // while (!st.empty())
    // {
    //     person chk;
    //     chk = st.pop();
    //     chk.print();
    //     // cout << st.pop() << endl;
    // }

    person chk;
    chk = st.Top();
    chk.print();

    return 0;
}