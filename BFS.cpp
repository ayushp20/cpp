#include<iostream>
using namespace std;

struct node
{
    int dest;
    node *next;
    int color;
    int dist;
    int parent;
};

struct AdjList
{
    node *head;
};

struct Graph
{
    int v;
    AdjList *list;
};

node *createnode(int d)
{
    node *info=new node;
    info->dest=d;
    info->next=NULL;
     return info;
}

Graph *createGraph(int v)
{
    Graph* info=new Graph;
    info->v=v;
    info->list=new AdjList[v];

    for(int i=0;i<v;i++)
        info->list[i].head=NULL;

    return info;
}

void addEdge(Graph *g,int src,int dest)
{
    node *info=createnode(dest);
    info->next=g->list[src].head;
    g->list[src].head=info;

    info=createnode(src);
    info->next=g->list[dest].head;
    g->list[dest].head=info;
}

void printGraph(Graph *g)
{
    for(int i=0;i<g->v;i++)
    {
        node*temp=g->list[i].head;

        while(temp)
        {
            cout<<"->"<<temp->dest;
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    Graph *g=createGraph(5);

    addEdge(g,0,1);
    addEdge(g,0,4);
    addEdge(g,1,2);
    addEdge(g,2,3);

    printGraph(g);

    return 0;
}
