#include <bits/stdc++.h>
using namespace std;

bool checkReduntantPairs(string expression)
{
    stack<char> st;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }

        else
        {
            // ya to ) bracket hoga ya letters
            if (ch == ')')
            {
                bool isReduntant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        isReduntant = false;

                    st.pop();
                }

                if (isReduntant == true)
                    return true;

                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string expression = "((a+b)+a*b)";

    if (checkReduntantPairs(expression))
        cout << "Reduntant\n";

    else
        cout << "Not Reduntant\n";
    return 0;
}