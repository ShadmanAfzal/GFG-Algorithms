#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> arr, int size)
{
    vector<int> dp(size, 1);
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] and dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<int> arr{50,3,10,7,40,80};
    int size = arr.size();
    cout << LIS(arr, size) << endl;
}
