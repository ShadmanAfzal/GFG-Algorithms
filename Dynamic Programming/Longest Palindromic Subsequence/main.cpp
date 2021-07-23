#include <bits/stdc++.h>
using namespace std;

int UsingRecursion(string str, int start, int end)
{
    if (start == end)
        return 1;

    if (str[start] == str[end] and start + 1 == end)
        return 2;

    if (str[start] == str[end])
        return 2 + UsingRecursion(str, start + 1, end - 1);

    return max(UsingRecursion(str, start + 1, end), UsingRecursion(str, start, end - 1));
}

int UsingDP(string str, int size)
{
    vector<vector<int>> dp(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++){
        dp[i][i] = 1;
    }

    for (int k = 2; k <= size; k++){
        for (int i = 0, j = i + k - 1; i < size - k + 1; i++, j++)
        {
            if(str[i]==str[j] and k==2)
                dp[i][j] = 2;
            else if(str[i]==str[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][size - 1];
}

int main()
{
    string str = "geeksforgeeks";
    cout << UsingDP(str,str.size());
}