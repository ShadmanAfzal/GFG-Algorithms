#include <bits/stdc++.h>
using namespace std;

class AdjNode
{
public:
    int v;
    int w;
    AdjNode(int v, int w) : v(v), w(w) {}
};

struct compare{
    bool operator()(AdjNode a, AdjNode b)
    {
        return a.w > b.w;
    }
};

class Graph{
public:
    int v;
    vector<AdjNode> *adj;

    Graph(int v){
        this->v = v;
        this->adj = new vector<AdjNode>[v];
    }

    void addEdge(int, int, int);
};

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(AdjNode(v,w));
    adj[v].push_back(AdjNode(u,w));
}

void djikstraAlgo(Graph* graph, int V){
    vector<int> val(V,1e8);
    vector<bool> mst(V,false);
    val[0] = 0;
    priority_queue<AdjNode, vector<AdjNode>, compare> pq;

    pq.push(AdjNode(0,0));

    while(!pq.empty()){
        int u = pq.top().v;
        pq.pop();

        if(mst[u] == true)
            continue;
        
        mst[u] = true;

        vector<AdjNode>::iterator it;
        for(it = graph->adj[u].begin(); it != graph->adj[u].end(); ++it){
            int v = it->v;
            int w = it->w;

            if(val[u] != 1e8 and val[u] + w < val[v]){
                val[v] = val[u]+w;
                pq.push(AdjNode(v,val[v]));
            }
        }
    }
    cout<<"Vextex\t\t"<<"Distance from Source vertex 0"<<endl;
    for(int i=0;i<val.size();i++){
        cout<<i<<"\t\t"<<val[i]<<endl;
    }
}



int main()
{
    int v = 9;
    Graph *graph = new Graph(v);
    graph->addEdge(0,1,4);
    graph->addEdge(0,7,8);
    graph->addEdge(1,2,8);
    graph->addEdge(1,7,11);
    graph->addEdge(2,3,7);
    graph->addEdge(2,8,2);
    graph->addEdge(2,5,4);
    graph->addEdge(3,4,9);
    graph->addEdge(3,5,14);
    graph->addEdge(4,5,10);
    graph->addEdge(5,6,2);
    graph->addEdge(6,7,1);
    graph->addEdge(6,8,6);
    graph->addEdge(7,8,7);

    djikstraAlgo(graph,v);
}