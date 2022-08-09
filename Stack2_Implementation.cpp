#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    // properties
    int *arr;
    int top;
    int size;

    Stack(int s)
    {
        this->size = s;
        arr = new int[size];
        top = -1;
    }

    // behaviour
    void push(int element)
    {
        // if(top<size-1)
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout << "Stack Overflow\n";
    }

    void pop()
    {
        if (top >= 0)
            top--;

        else
            cout << "Stack Underflow\n";
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];

        else
        {
            cout << "Stack is empty\n";
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top < 0)
            return true;

        else
            return false;
    }
};

int main()
{
    Stack st(5);
    st.push(3);
    st.push(7);
    st.push(10);
    st.push(10);
    st.push(18);
    st.push(19);
    st.push(19);
    cout << "Peek element is " << st.peek() << endl;
    st.pop();
    cout << "Peek element is " << st.peek() << endl;
    st.pop();
    st.pop();
    cout << st.peek() << endl;
    if (st.isEmpty())
        cout << "Stack Is Empty\n";
    else
        cout << "Stack is not Empty\n";
    return 0;
}