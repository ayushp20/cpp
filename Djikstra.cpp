#include<bits/stdc++.h>
using namespace std;

int Min(int a[],int v,bool mst[])
{
    int min=INT_MAX,index;

    for(int i=0;i<v;i++)
        if((mst[i]!=1)&&(a[i]<min))
        {
            min=a[i];
            index=i;

        }
    return index;
}

void SPT(int v)
{
    cout<<"\nEnter Adjacency Matrix:\n";
    int a[v][v]= {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    int dist[v],parent[v];
    bool mst[v];

    //initializing arrays
    for(int i=0;i<v;i++)
        mst[i]=0,dist[i]=INT_MAX;

    dist[0]=0;
    parent[0]=-1;

    //Dijkstra's Function
    for(int i=0;i<v;i++)
    {
        //find min
        int index=Min(dist,v,mst);
        mst[index]=1;//put in found subset

        for(int j=0;j<v;j++)
            if(mst[j]==0&&a[index][j]!=0)//not found && edge exists
                if(dist[j]>a[index][j]+dist[index])
                {
                    dist[j]=a[index][j]+dist[index];
                    parent[j]=index;

                }

    }

    for(int i=0;i<v;i++)
    {
        cout<<src<<" to "<<i<<"___"<<dist[i]<<endl;
    }
}
int main()
{
    cout<<"\nEnter Number of Vertices : ";
    int n;
    cin>>n;

    SPT(n);
}
