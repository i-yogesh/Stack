#include <bits/stdc++.h>
using namespace std;

int validString(string expression)
{
    if (expression.length() % 2 == 1)
        return -1;

    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (ch == '{')
        {
            s.push(ch);
        }
        else
        // ch is closing bracket
        {
            // as ch is closing we need to have an opening bracket
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }

            else
            {
                s.push(ch);
            }
        }
    }

    // now invalid expression only remains
    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
            b++;

        else
            a++;

        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string expression = "}}{{";
    int ans = validString(expression);
    cout << ans << endl;
    return 0;
}