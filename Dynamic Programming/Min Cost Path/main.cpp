#include <bits/stdc++.h>
using namespace std;

int FindMinCostPath(vector<vector<int>> cost, int row, int col)
{
    vector<vector<int>> dp(row,vector<int>(col));
    dp[0][0] = cost[0][0];
    for(int i=1;i<row;i++)
        dp[i][0] = dp[i-1][0] + cost[i][0];
    for(int j=1;j<col;j++)
        dp[0][j] = dp[0][j-1] + cost[0][j];

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + cost[i][j];
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[row-1][col-1];
}

int main()
{
    vector<vector<int>> arr{{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}};
    int row = arr.size();
    int col = arr[0].size();
    cout<<FindMinCostPath(arr,row,col);
}