#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    vector<int> *arr;

    Graph(int v)
    {
        this->v = v;
        this->arr = new vector<int>[v];
    }

    void addEdge(int x, int y)
    {
        arr[y].push_back(x);
    }
};

void fillStack(vector<bool> &visited, stack<int> &s, int curr, Graph *graph)
{
    visited[curr] = true;
    vector<int>::iterator it = graph->arr[curr].begin();
    for (; it != graph->arr[curr].end(); ++it)
    {
        if (!visited[*it])
            fillStack(visited, s, *it, graph);
    }
    s.push(curr);
}

Graph *transpose(Graph *graph)
{
    Graph *transposeGraph = new Graph(graph->v);

    for (int i = 0; i < graph->v; i++)
    {
        for (auto it = graph->arr[i].begin(); it != graph->arr[i].end(); ++it)
        {
            transposeGraph->addEdge(*it, i);
        }
    }
}

void DFS(int curr, vector<bool> &visited, Graph *graph)
{
    visited[curr] = true;

    vector<int>::iterator it = graph->arr[curr].begin();
    cout<<curr<<" ";
    for (; it != graph->arr[curr].end(); ++it)
    {
        if (!visited[*it])
        {
            DFS(*it, visited, graph);
        }
    }
}

int solution(int n, int p, int a[], int b[], int d[])
{
    int count = 0;
    Graph *graph = new Graph(n);
    for (int i = 0; i < p; i++)
    {
        graph->addEdge(a[i], b[i]);
    }
    vector<bool> visited(n, false);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            fillStack(visited, s, i, graph);
    }

    Graph *transposeGraph = transpose(graph);
    for (int i = 0; i < visited.size(); i++)
    {
        visited[i] = false;
    }
    
    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        if(curr == 0)
            continue;
        if (!visited[curr])
        {
            DFS(curr, visited, transposeGraph);
            count++;
            cout<<endl;
        }
    }
    return count;
}

int main()
{
    int n = 9, p = 6;
    int a[] = {7, 5, 4, 2, 9, 3};
    int b[] = {4, 9, 6, 8, 7, 1};
    int d[] = {98, 72, 10, 22, 17, 66};
    cout<<solution(n+1,p,a,b,d);
}