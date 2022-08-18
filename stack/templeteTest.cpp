#include <bits/stdc++.h>
using namespace std;

template <typename T>
T myMax(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << myMax<int>(5, 7) << endl;
    cout << myMax<float>(5.6, 7.9) << endl;
    cout << myMax<char>('a', 'k') << endl;

    return 0;
}