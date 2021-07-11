#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int buy;
    int sell;
};

vector<vector<int>> stockBuySell(vector<int> A, int n)
{
    vector<vector<int>> result;

    if (n == 1)
        return result;

    int count = 0;

    Interval sol[n / 2 + 1];

    int i = 0;
    while (i < n - 1)
    {

        while ((i < n - 1) && (A[i + 1] <= A[i]))
            i++;

        if (i == n - 1)
            break;

        sol[count].buy = i++;

        while ((i < n) && (A[i] >= A[i - 1]))
            i++;

        sol[count].sell = i - 1;

        count++;
    }

    if (count == 0)
        return result;
    else
    {

        for (int i = 0; i < count; i++)
        {
            vector<int> temp;
            temp.push_back(sol[i].buy);
            temp.push_back(sol[i].sell);
            result.push_back(temp);
        }
    }

    return result;
}

int main()
{
    vector<int> arr{11, 42, 49, 96, 23, 20, 49, 26, 26, 18, 73, 2, 53, 59, 34, 99, 25, 2};
    vector<vector<int>> sol = stockBuySell(arr, arr.size());
    for (int i = 0; i < sol.size(); i++)
    {
        for (int j = 0; j < sol[0].size(); j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}