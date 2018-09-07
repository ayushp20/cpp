#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v,e;
    vector<pair<int,pair<int,int> > > edge;

    Graph(int v,int e)
    {
        this->v=v;
        this->e=e;
    }

    void addEdge(int wt,int src,int dest)
    {
        edge.push_back({wt,{src,dest}});
    }

    void djikstra(int);
};

void Graph::djikstra(int src)
{
    int dist[v];

    for(int i=0;i<v;i++)
        dist[i]=INT_MAX;


    dist[src]=0;

    for(int i=0;i<v-1;i++)
        for(int j=0;j<e;j++)
        {
            int u=edge[j].second.first;
            int v=edge[j].second.second;
            int wt=edge[j].first;

            if(dist[u]!=INT_MAX&&(dist[u]+wt)<dist[v])
                dist[v]=dist[u]+wt;

        }

    for(int i=0;i<v;i++)
    {
        cout<<src<<" to "<<i<<" --= "<<dist[i]<<endl;
    }
}


int main()
{
    Graph g(4,12);
    g.addEdge(1,0,3);
    g.addEdge(2,0,1);
    g.addEdge(10,0,2);


    g.addEdge(2,1,0);
    g.addEdge(3,1,2);
    g.addEdge(20,1,3);

    g.addEdge(10,2,0);
    g.addEdge(3,2,3);
    g.addEdge(3,2,1);

    g.addEdge(20,3,1);
    g.addEdge(1,3,0);
    g.addEdge(3,3,2);



    g.djikstra(2);
}
