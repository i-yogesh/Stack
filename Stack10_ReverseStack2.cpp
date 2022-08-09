#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    // Recursive Call
    reverseStack(s);

    s.push(num);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(6);
    s.push(22);
    s.push(333);
    s.push(4444);

    reverseStack(s);

    return 0;
}