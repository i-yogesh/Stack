#include <bits/stdc++.h>
using namespace std;

bool checkParenthesis(string expression)
{
    stack<char> st;

    for (int i = 0; i < expression.length(); i++)
    {
        // opening bracket
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }

        // closing bracket
        else
        {
            if (!st.empty())
            {
                char top = st.top();

                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    st.pop();
                }

                else
                {
                    return false;
                }
            }

            else
            {
                return false;
            }
        }
    }
    // cout<<st.top();

    if (st.empty())
        return true;

    else
        return false;
}

int main()
{
    string expression = "({({[()]})})";
    if (checkParenthesis(expression))
        cout << "Balanced\n";

    else
        cout << "Unbalanced\n";
    return 0;
}