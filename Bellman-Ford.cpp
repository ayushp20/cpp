#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest,wt;
};

struct Graph
{
    int v,e;
    Edge *edge;

    Graph(int v,int e)
    {
        this->v=v;
        this->e=e;
        this->edge=new Edge[e];
    }
};

void BellmanFord(Graph *graph,int src)
{
    int dist[graph->v];

    for(int i=0;i<graph->v;i++)
        dist[i]=INT_MAX;

    dist[src]=0;


    for(int i=0;i<graph->v-1;i++)
        for(int j=0;j<graph->e;j++)
        {
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int w=graph->edge[j].wt;

            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
                dist[v]=dist[u]+w;
        }

    for(int j=0;j<graph->e;j++)
    {
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int w=graph->edge[j].wt;

            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
                {
                    cout<<"Negative Cycle Exists\n";
                    return;
                }
    }

    for(int i=0;i<graph->v;i++)
    {
        cout<<src<<" to "<<i<<"___"<<dist[i]<<endl;
    }

}

int main()
{
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    Graph* graph=new Graph(V,E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].wt = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].wt = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].wt = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].wt = 2;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].wt = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].wt = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].wt = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].wt = -3;

    BellmanFord(graph,0);

    return 0;
}
