#include <bits/stdc++.h>
using namespace std;

int MinEdit(string a, string b, int m, int n)
{
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dp[i][j] = j;

            else if(j==0)
                dp[i][j] = i;

            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];
}

int main()
{
    string a = "sunday";
    string b = "saturday";
    cout<<MinEdit(a,b,a.size(),b.size());
}