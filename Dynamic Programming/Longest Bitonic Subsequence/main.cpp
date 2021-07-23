#include <bits/stdc++.h>
using namespace std;

int LBS(vector<int> arr)
{
    vector<int> dp(arr.size(),1);
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] and dp[i] < dp[j]+1)
                dp[i] = dp[j]+1;
        }
    }

    vector<int> dp1(arr.size(),1);
    for(int i=0; i<arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] < arr[j] and dp1[i] < dp1[j]+1)
                dp1[i] = dp1[j]+1;
        }
    }

    int maxval = INT_MIN;
    for(int i=0;i<arr.size();i++)
        maxval = max(maxval, dp[i]+dp1[i]-1);
    return maxval; 
}

int main()
{
    vector<int> arr{80, 60, 30, 40, 20, 10};
    cout<<LBS(arr);
}