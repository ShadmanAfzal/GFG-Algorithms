#include <bits/stdc++.h>
using namespace std;

int usingRecursion(int price[],int size)
{
    if(size<=0)
        return 0;
    
    int maxVal = INT_MIN;

    for(int i=0;i<size;i++){
        maxVal = max(maxVal,price[i]+usingRecursion(price,size-i-1));
    }

    return maxVal;
}

int usingDP(int price[],int size){
    
    int dp[size+1];

    dp[0] = 0;

    for(int i = 1;i<size;i++){
        int maxVal = INT_MIN;
        for(int j=0;j<i;j++){
            maxVal = max(maxVal,price[j]+dp[size-i-1]);
        }
        dp[i] = maxVal;
    }
    return dp[size];
}

int main()
{
    int arr[] = {1, 2,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<usingRecursion(arr,size);
}