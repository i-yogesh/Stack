#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;
    string str = "Titanic";
    string ans = "";
    int i;
    for (i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        st.push(ch);
    }

    // reverse
    while (!st.empty())
    {
        char ch = st.top();
        ans.push_back(ch);

        st.pop();
    }

    cout << ans << endl;
}