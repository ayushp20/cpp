#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ipair;

struct Graph
{
    int v,e;
    vector<pair<int,ipair>> edge;

    Graph(int v,int e)
    {
        this->v=v;
        this->e=e;
    }

    void addEdge(int src,int dest,int wt)
    {
        edge.push_back({wt,{src,dest}});
    }

    int BellmanFord(int);
};

int Graph::BellmanFord(int src)
{
    int dist[v];

    for(int i=0;i<v;i++)
        dist[i]=INT_MAX;

    dist[src]=0;

    for(int i=0;i<v;i++)
        for(int j=0;j<e;j++)
        {
            int u=edge[j].second.first;
            int v=edge[j].second.second;
            int w=edge[j].first;

            if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
                    dist[v]=dist[u]+w;

        }
        for(int i=0;i<v;i++)
    {
        cout<<src<<" to "<<i<<"___"<<dist[i]<<endl;
    }

         for(int j=0;j<e;j++)
        {
            int u=edge[j].second.first;
            int v=edge[j].second.second;
            int w=edge[j].first;

            if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
            {
                cout<<"Negative Cycle Exists : ";
                break;
            }

        }


}

int main()
{
    Graph g(9,14);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout<<g.BellmanFord(0)<<endl;
}
