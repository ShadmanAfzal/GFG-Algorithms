#include <bits/stdc++.h>
using namespace std;

int highestToLeft(vector<int> arr, int pos)
{
    int max = arr[pos];
    for(int i=0;i<pos;i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

int highestToRight(vector<int> arr, int pos)
{
    int max = arr[pos];
    for(int i=pos+1;i<arr.size();i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

vector<int> findLeft(vector<int> level)
{
    int maxLevel = 0;
    vector<int> maxLeft(level.size());
    for(int i=0;i<level.size();i++)
    {
        maxLeft[i] = maxLevel;
        maxLevel = max(maxLevel,level[i]);
    }
    return maxLeft;
}

vector<int> findRight(vector<int> level)
{
    int maxLevel = 0;
    vector<int> maxRight(level.size());
    for(int i=level.size()-1;i>=0;i--)
    {
        maxRight[i] = maxLevel;
        maxLevel = max(maxLevel,level[i]);
    }
    return maxRight;   
}

int solve(vector<int> level)
{
    int size = level.size();
    vector<int> left = findLeft(level);
    for(int i:left)
        cout<<i<<" ";
    cout<<endl;
    vector<int> right = findRight(level);
    for(int i:right)
        cout<<i<<" ";
    cout<<endl;
    int sol = 0;
    for(int i=1;i<size-1;i++)
    {
        sol += min(left[i],right[i]) - level[i];
    }
    return sol;
}

int main()
{
    vector<int> level {4,2,0,3,2,5};
    cout<<solve(level);
}