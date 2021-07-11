#include <bits/stdc++.h>
using namespace std;

int JumpSearch(vector<int> arr, int steps, int x)
{
    int count = 1;
    for (int i = 0; i < arr.size(); i += steps)
    {
        cout << arr[i] << endl;
        if (x == arr[i])
            return i;
        else if (x < arr[i])
        {
            for (int j = i - steps; j < i; j++)
            {
                cout << arr[j] << endl;

                // cout << count++ << endl;
                if (arr[j] == x)
                {
                    return j;
                    break;
                }
            }
            break;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{0, 1, 1, 2, 5, 8, 13, 21,
                    34, 55, 89, 144, 233, 610};
    int searchEle = 144;
    int steps = sqrt(arr.size());
    cout << JumpSearch(arr, steps, searchEle);
}