#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int element)
{
    if (s.empty() || (!s.empty() && s.top() < element))
    {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();

    // Recursive Call
    sortedInsert(s, element);

    s.push(top);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    // Recursive Call
    sortStack(s);

    sortedInsert(s, num);
}

int main()
{
    stack<int> s;
    s.push(9);
    s.push(12);
    s.push(4);
    s.push(0);

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}