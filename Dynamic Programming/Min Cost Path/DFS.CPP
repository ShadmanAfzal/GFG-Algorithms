#include <bits/stdc++.h>
using namespace std;

struct Move
{
    int x, y, distance;
};

bool operator<(Move a, Move b)
{
    if(a.distance == b.distance)
    {
        if(a.x != b.x)
            return a.x < b.x;
        else
            return a.y < b.y;
    }
    return a.distance < b.distance;
}


bool isvalid(int x,int y,int row,int col)
{
    return (x>=0 and x<row and y>=0 and y<col);
}

int FindMinCostPath(vector<vector<int>> cost, int row, int col)
{
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    vector<vector<int>> value(row, vector<int>(col, INT_MAX));
    value[0][0] = cost[0][0];
    set<Move> st;
    st.insert({0, 0, 0});
    Move move;
    while (!st.empty())
    {
        move = *st.begin();
        st.erase(st.begin());

        for (int i = 0; i < 4; i++)
        {
            int x = move.x + dx[i];
            int y = move.y + dy[i];

            if(isvalid(x,y,row,col) and value[x][y] > value[move.x][move.y] + cost[x][y])
            {
                if(value[x][y] != INT_MAX)
                    st.erase(st.find({x,y,move.distance}));

                value[x][y] = value[move.x][move.y] + cost[x][y];
                st.insert({x,y,value[x][y]});
            }

        }
    }
    return value[row-1][col-1];
}

int main()
{
    vector<vector<int>> arr{{9, 4, 9, 9}, {6, 7, 6, 4}, {8, 3, 3, 7}, {7, 4, 9, 10}};
    int row = arr.size();
    int col = arr[0].size();
    cout << FindMinCostPath(arr, row, col);
}