#include <bits/stdc++.h>
using namespace std;
// 0 1 2 3 4 5 6 7

int findPossibleCombination(vector<int> list, int n)
{
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=0;i<list.size();i++)
    {
        for(int j=list[i];j<dp.size();j++)
        {
            dp[j] += dp[j-list[i]];

        }
    }

    return dp[n];
}

int main()
{
    vector<int> arr {2,3,5};
    cout<<findPossibleCombination(arr,7);
}