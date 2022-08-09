#include <bits/stdc++.h>
using namespace std;

void deleteMiddleElement(stack<int> &st, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();
    // Recursive Call
    deleteMiddleElement(st, count + 1, size);

    st.push(num);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    int size = st.size();
    deleteMiddleElement(st, 0, size);

    while (!st.empty())
    {
        int ans = st.top();
        cout << ans << " ";
        st.pop();
    }
    // cout<<st.top()<<endl;
    return 0;
}