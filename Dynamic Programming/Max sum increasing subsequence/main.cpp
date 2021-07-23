#include <bits/stdc++.h>
using namespace std;

int findMaxSumLIS(vector<int> arr, int size)
{
    int dp[size];

    for(int i=0;i<size;i++){
        dp[i] = arr[i];
    }

    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] and dp[i] < arr[i]+dp[j])
                dp[i] = arr[i]+dp[j];
        }
    }

    return *max_element(dp,dp+size);
}

int main()
{
    vector<int> arr{1, 101, 2, 3, 100, 4, 5};
    cout<<findMaxSumLIS(arr,arr.size());
}