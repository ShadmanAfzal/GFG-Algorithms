#include <bits/stdc++.h>
using namespace std;

int MinTries(int eggs, int floor)
{
    vector<vector<int>> dp(eggs+1,vector<int>(floor+1,0));
    for(int i=1;i<=eggs;i++)
    {
        for(int j=1;j<=floor;j++)
        {
            if(i==1)
                dp[i][j] = j;
            else if(j==1)
                dp[i][j] = 1;
            else{
                int p = j-1 , q = 0;
                int minVal = INT_MAX;
                for(;p>=0;p--,q++)
                {
                    int v1 = dp[i][p];
                    int v2 = dp[i-1][q];
                    int val = max(v1,v2);
                    minVal = min(minVal,val);
                }
                dp[i][j] = minVal + 1;
            }
        }
    }
    return dp[eggs][floor];
}

int main()
{
    int eggs = 2, floor = 36;
    cout<<MinTries(eggs,floor);
}