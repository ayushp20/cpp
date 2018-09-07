#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int prims(int v)
{
    int a[v][v]={     {0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    /*for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>a[i][j];*/

    //Zeroes to INF
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            if(a[i][j]==0)
                a[i][j]=INF;


    int mstwt=0;
    int key[v],parent[v];

    //parent NOT a necessary array but imp. for printing properly
    parent[0]=-1;
    //Iniatializing Key
    for(int k=0;k<v;k++)
        key[k]=INF;
    // prims function
    for(int i=0;i<v-1;i++)
    {
        for(int j=i+1;j<v;j++)
            if(key[j]>a[i][j])
            {
                key[j]=a[i][j];
                parent[j]=i;
            }
         int min=INF,min_in;
         for(int k=0;k<v;k++)
                if(key[k]<min)
                {
                    min=key[k];
                    min_in=k;
                }
         if(min!=INF)
            {
                cout<<parent[min_in]<<"--"<<min_in<<"\t"<<min<<endl;
                mstwt+=min;
                key[min_in]=INF;
            }
    }

        cout<<mstwt;
}



 int main()
{
    cout<<"\nEnter the number of vertices : ";
    int v;
    cin>>v;
    cout<<"\nEnter Adjacency Matrix : \n";

    prims(v);


return 0;
}
