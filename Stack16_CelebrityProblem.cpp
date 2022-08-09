#include <bits/stdc++.h>
using namespace std;

bool knows(int arr[3][3], int a, int b)
{
    if (arr[a][b] == 1)
        return true;

    else
        return false;
}
int celebrityProblem(int arr[3][3], int n)
{
    stack<int> s;

    // step1: putting all elements in stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // step2: get 2 elements and compare them
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        // comapre
        if (knows(arr, a, b)) // if a knows b discard a and put b
            s.push(b);

        else
            s.push(a);
    }
    // top is potential candidate
    int candidate = s.top();

    // rowCheck , celebrity knows no one
    int rowCount = 0;
    bool rowCheck = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[candidate][i] == 0)
            rowCount++;
    }

    if (rowCount == n)
        rowCheck = true;

    // column check, everyone knows celebrity
    int columnCount = 0;
    bool columnCheck = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[i][candidate] == 1)
            columnCount++;
    }

    if (columnCount == n - 1)
        columnCheck = true;

    // last step to see if both conditions satisfy
    if (rowCheck == true && columnCheck == true)
        return candidate;

    else
        return -1;
}

int main()
{
    int arr[3][3]{
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}};
    int n = 3;
    int ans = celebrityProblem(arr, n);
    cout << ans << endl;
    return 0;
}