#include <bits/stdc++.h>
using namespace std;

void nextSmallestElement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);
    int ans[10];
    // vector<int> ans;

    for (int i = n-1; i >= 0 ; i--)
    {
        int curr = arr[i];
        while(s.top() >= curr )
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    // return ans;
}

int main()
{
    int arr[] = {2, 1, 4, 3};
    int n = 4;
    nextSmallestElement(arr, n);
   
    //give -1 if none of the next element is not smaller than it otherwise store the smalller number
    return 0;
}