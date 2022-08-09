#include <bits/stdc++.h>
using namespace std;

class NStack
{
public:
    int *arr;
    int *top;
    int *next;

    int n, s;

    int freespot;

    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        top[n] = {-1};

        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // update last index
        next[s - 1] = -1;

        // initialise freespot
        freespot = 0;
    }

    bool push(int x, int m)
    {
        // x is the element to be inserted and m is the stack no

        if (freespot == -1)
            return false;

        // step 1 : find index
        int index = freespot;

        // step 2 : update freespot
        freespot = next[index];

        // step3: insert the element in the array
        arr[index] = x;

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{
    int n = 3, s = 10;
    NStack obj(n, s);
    cout << "Push's result " << obj.push(10, 1) << endl;
    cout << "Push's result " << obj.push(10, 1) << endl;

    cout << "Pop's result " << obj.pop(1) << endl;
    return 0;
}