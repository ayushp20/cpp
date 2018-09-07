#include<bits/stdc++.h>
using namespace std;

struct mystack{
    int data[4];
    int top;
    stack()
    {
        top=-1;
    }
    void push(int d)
    {
        if(top==4)
            cout<<"Overflow";
        else{
            top++;
            data[top]=d;
        }
    }

    void pop()
    {
        if(top==-1)
            cout<<"Underflow\n";
        else{
            cout<<data[top]<<endl;
            top--;
        }
    }

};
DFS()
{
    int v;
    cout<<"Enter Number of Vertices : ";
    cin>>v;
    int a[v][v]={{0,9,7,0},{9,0,0,5},{7,0,0,0},{0,5,0,0}};

    mystack s;
    bool visited[v]={0};
    s.push(0);
    visited[0]=1;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            if(a[i][j]!=0&&visited[j]==0)
                {s.push(j); visited[j]=1;}

        s.pop();
    }
}


int main()
{
    DFS();
       return 0;
}
