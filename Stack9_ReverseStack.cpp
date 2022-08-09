#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int element) 
{
    //base case
    if(s.empty())
    {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();

    //Recursive Call
    insertAtBottom(s,element);

    s.push(top);
}

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

    insertAtBottom(s,num);

}

int main()
{
    stack<int> s;
    s.push(6);
    s.push(22);
    s.push(333);
    s.push(4444);

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}