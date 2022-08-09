#include <bits/stdc++.h>
#define MAX 100
using namespace std;

vector<int> prevSmallerElement(int *arr, int m)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(m);

    for (int i = 0; i < m; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextSmallerElement(int *arr, int m)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(m);

    for (int i = m - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] > curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


int largestRectangularAreaInHistogram(int *arr, int m)
{
    vector<int> next(m);
    next = nextSmallerElement(arr, m);

    vector<int> prev(m);
    prev = prevSmallerElement(arr, m);

    int area = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        int l = arr[i];

        if (next[i] == -1)
        {
            next[i] = m;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int maxRectangleInBinaryMatrixWithAll1(int arr[MAX][MAX], int n, int m)
{
    // first compute the first row area
    int area = largestRectangularAreaInHistogram(arr[0], m);

    // find area for remaining rows
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // row update: adding previous row's value
            if (arr[i][j] != 0)
                arr[i][j] = arr[i][j] + arr[i - 1][j];

            else
                arr[i][j] = 0;
        }
        // now the row is updated
        int newArea = largestRectangularAreaInHistogram(arr[i], m);
        area = max(area, newArea);
    }

    return area;
}
int main()
{
    int arr[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };
    int n = 4,
        m = 4;
    int ans = maxRectangleInBinaryMatrixWithAll1(arr, n, m);
    cout << ans << endl;
}

// { Driver Code Starts.
// int main() {
//     int T;
//     cin >> T;

//     int M[MAX][MAX];

//     while (T--) {
//         int n, m;
//         cin >> n >> m;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 cin >> M[i][j];
//             }
//         }
//         cout << maxRectangleInBinaryMatrixWithAll1(M, n, m) << endl;
//     }
// }