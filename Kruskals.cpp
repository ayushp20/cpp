#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ipair;

struct Graph
{
    int V,E;
    vector<pair<int,ipair>> edge;

    Graph(int V,int E)
    {
        this->V=V;
        this->E=E;
    }

    void addEdge(int u,int v,int w)
    {
        edge.push_back({w,{u,v}});
    }

    int kruskalMST();
};

struct sets
{
    int *parent,*rank;
    int n;

    sets(int n)
    {
        this->n=n;
        parent=new int[n+1];
        rank=new int[n+1];

        for(int i=0;i<=n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
    }

    int find(int u)
    {
        if(u!=parent[u])
            parent[u]=find(parent[u]);
        return parent[u];
    }

    void merge(int u,int v)
    {
        int x=find(u);
        int y=find(v);


        if(rank[x]>rank[y])
            parent[y]=x;
        else
            parent[x]=y;

        if(rank[x]==rank[y])
            rank[y]++;
    }
};

int Graph::kruskalMST()
{
    int mst_wt=0;

    sort(edge.begin(),edge.end());

    sets ds(V);

    vector<pair<int,ipair>>::iterator it;
    for(it=edge.begin();it!=edge.end();it++)
    {
        int u=it->second.first;
        int v=it->second.second;

        int set_u=ds.find(u);
        int set_v=ds.find(v);

        if(set_u!=set_v)
        {
            cout<<u<<" -- "<<v<<endl;
            mst_wt+=it->first;

            ds.merge(set_u,set_v);
        }

    }

    return mst_wt;
}
int main()
{
    int v=9,e=14;
    Graph g(v,e);

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

    cout << "edge of MST are \n";
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;


    return 0;
}
