#include <bits/stdc++.h>
using namespace std;

struct Coordinate
{
    int north, south;
};

bool compare(Coordinate a, Coordinate b)
{
    if (a.north == b.north)
        return a.south < b.south;
    return a.north < b.north;
}

int main()
{
    vector<Coordinate> coordinate{{6, 2}, {4, 3}, {2, 6}, {1, 5}};
    sort(coordinate.begin(), coordinate.end(), compare);
    vector<int> dp(coordinate.size(),1);

    for (int i = 0; i < coordinate.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (coordinate[i].south > coordinate[j].south and dp[j] >= dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    cout <<*max_element(dp.begin(),dp.end());
}