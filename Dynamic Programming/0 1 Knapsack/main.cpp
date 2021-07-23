#include <bits/stdc++.h>
using namespace std;

int findMaxProfit(vector<int> profit, vector<int> weight, int size, int W)
{
    int dp[size+1][W+1];

    for(int i=0;i<=size;i++)
    {
        for(int w=0; w<=W; w++)
        {
            if(i==0 || w==0)
            {
                dp[i][w] = 0;
            }
            else if(weight[i-1] <= w)
            {
                dp[i][w] = max((profit[i-1]+dp[i-1][w - weight[i-1]]), dp[i-1][w]);
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[size][W];
}

int main()
{
    int W = 50;
    vector<int> profit{60, 100, 120};
    vector<int> weight{10, 20, 30};
    int size = profit.size();
    cout<<findMaxProfit(profit,weight,size,W);
}