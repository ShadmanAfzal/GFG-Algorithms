#include <bits/stdc++.h>
using namespace std;

struct Cell
{
    int x, y, distance;
    Cell() {}
    Cell(int x, int y, int distance)
    {
        this->x = x;
        this->y = y;
        this->distance = distance;
    }
};

bool operator<(Cell a, Cell b)
{
    if (a.distance == b.distance)
    {
        if (a.x != b.x)
            return a.x < b.x;
        else
            return a.y < b.y;
    }
    return (a.distance < b.distance);
}

bool isvalid(int i, int j, int N)
{
    return (i >= 0 and i < N and j >= 0 and j < N);
}

int minimumCostPath(vector<vector<int>> &grid)
{
    Cell cell;
    int N = grid.size();
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    vector<vector<int>> distance(N, vector<int>(N, INT_MAX));
    set<Cell> st;
    st.insert(Cell(0, 0, 0));
    distance[0][0] = grid[0][0];
    while (!st.empty())
    {
        cell = *st.begin();
        st.erase(st.begin());

        for (int i = 0; i < 4; i++)
        {
            int di = cell.x + dx[i];
            int dj = cell.y + dy[i];

            if (!isvalid(di, dj, N) and distance[di][dj] > distance[cell.x][cell.y] + grid[di][dj])
            {
                if (distance[di][dj] != INT_MAX)
                    st.erase(st.find(Cell(di, dj, distance[di][dj])));

                distance[di][dj] = distance[cell.x][cell.y] + grid[di][dj];
                st.insert(Cell(di, dj, distance[di][dj]));
            }
        }
    }

    return distance[N - 1][N - 1];
};

int main()
{
    vector<vector<int>> grid{{9, 4, 9, 9}, {6, 7, 6, 4}, {8, 3, 3, 7}, {7, 4, 9, 10}};
    cout << minimumCostPath(grid);
}