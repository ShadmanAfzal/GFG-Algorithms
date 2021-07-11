#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> LCS(string A, string B, int n, int m)
{
	vector<vector<int>> dp(n+1,vector<int>(m+1));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp;
}

int main()
{
	string A = "AGGTAB";
	string B = "GXTXAYB";
	vector<vector<int>> result = LCS(A, B, A.size(), B.size());
	for(int i=0;i<result.size();i++)
	{
		for(int j:result[i])
			cout<<j<<" ";
		cout<<endl;
	}
	cout<<result[A.size()][B.size()];
}
