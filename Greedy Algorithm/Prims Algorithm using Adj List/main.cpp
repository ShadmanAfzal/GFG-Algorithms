#include <bits/stdc++.h>
using namespace std;

class AdjNode{
public:
    int v;
    int w;
    AdjNode(int v,int w){
        this->v = v;
        this->w = w;
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

    void addEdge(int, int,int);
};

void Graph::addEdge(int u,int v,int w){
    adj[u].push_back(AdjNode(v,w));
    adj[v].push_back(AdjNode(u,w));
}

void printPrims(vector<int> parent, vector<int> val){
    for(int i=0;i<parent.size();i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
}

struct compare{
    bool operator()(AdjNode a, AdjNode b)
    {
        return a.w > b.w;
    }
};

void primsAlgo(Graph* graph, int v){
    
    priority_queue<AdjNode, vector<AdjNode>, compare> pq;
    vector<int> val(v,INT_MAX);
    val[0] = 0;
    vector<int> mst(v,false);
    vector<int> parent(v,-1);
    pq.push(AdjNode(0,0));
    while(!pq.empty()){
        int u = pq.top().v;
        pq.pop();

        if(mst[u] == true)
            continue;

        mst[u] = true;
        vector<AdjNode>::iterator it;
        for(it = graph->adj[u].begin(); it != graph->adj[u].end();++it){
            
            int v = it->v;
            int w = it->w;
            
            if(!mst[it->v] and w < val[v])
            {
                val[v] = w;
                pq.push(AdjNode(v,val[v]));
                parent[v] = u;
            }
        }
    }

    printPrims(parent,val);
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

    primsAlgo(graph,v);
}