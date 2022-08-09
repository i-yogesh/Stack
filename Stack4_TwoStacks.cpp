#include <bits/stdc++.h>
using namespace std;

class TwoStacks
{
public:
    int top1;
    int top2;
    int *arr;
    int size;

    TwoStacks(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }

        else
        cout << "Stack Overflow\n";
    }

    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
        else
        cout << "Stack Overflow\n";

    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int val = arr[top1];
            top1--;
            return val;
        }
        else
        {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    int pop2()
    {
        if (top2 < size)
        {
            int val = top2;
            top2++;
            return val;
        }
        else
        {
            cout << "Stack Underflow\n";
            return -1;
        }
    }
};

int main()
{
    int n = 5;
    TwoStacks st(n);
    st.pop1();
    // st.push1(5);
    // cout<<st.arr[n];
    return 0;
}