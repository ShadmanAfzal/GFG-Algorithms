#include <bits/stdc++.h>
using namespace std;

void naiveSol(vector<int> arr, vector<int> dept, int n)
{
    int platform = 1;
    int result = 1;
    for (int i = 0; i < n; i++)
    {   
        platform = 1;
        for (int j = i + 1; j < n; j++)
        {   
            if ((arr[i] >= arr[j] and arr[i] <= dept[j]) || (arr[j] >= arr[i] and dept[i] >= arr[j]))
                platform++;
        }

        result = max(result,platform);
    }
    cout << result;
}

int main()
{
    vector<int> arr{1,3,0,5,8,5};
    vector<int> dept{2,4,6,7,9,9};
    naiveSol(arr, dept, arr.size());
}