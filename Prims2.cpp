#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v,e;
    vector<pair<int,pair<int,int>>> edge;

    Graph(int v,int e)
    {
        this->v=v;
        this->e=e;
    }

    void addEdge(int wt,int src,int dest)
    {
        edge.push_back({wt,{src,dest}});
    }

    void prims();
};

void Graph::prims()
{
    int dist[v],mst[v];

    for(int i=0;i<v;i++)
        dist[i]=INT_MAX,mst[i]=0;

    dist[0]=0;

    for(int i=0;i<v-1;i++)
    {
        int u=min(dist);


        mst[u]=1;

        for(int j=0;j<e;j++)
        {
            int v=edge[j].second.second;
            if(edge[j].second.first==u&&mst[v]==0)
                if(edge[j].first<dist[v])
                    dist[v]=edge[j].first;
        }

    }

    for(int i=0;i<v;i++)
        mstwt+=dist[i];

    cout<<mstwt<<endl;
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



    g.prims();
}
