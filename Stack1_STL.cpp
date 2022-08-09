#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(17);

    cout << "Peek element is " << st.top() << endl;
    st.pop();
    cout << "Peek element is " << st.top() << endl;
    st.pop();
    // st.pop();
    // st.pop();
    if (st.empty())
        cout << "Stack is empty\n";
    else
        cout << "Peek element is " << st.top() << endl;

    return 0;
}