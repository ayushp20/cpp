#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  node *link;

};
class queue
{
  node *head,*tail;
    public:
    queue()
    {
        head=tail=NULL;
    }
    void enqueue(int data)
    {
        node *newnode=new node;
        newnode->link=NULL;
        newnode->data=data;
        if(head==NULL)
        {

            head=tail=newnode;
        }
        else
        {
            tail->link=newnode;
            tail=newnode;
        }
    }
    void dequeue()
    {
        if(head==NULL)
        {
            return;
        }
        else
        {
            node *t=head;
            head=head->link;
            delete t;
            if(head==NULL)
                tail=NULL;
        }
    }
    void printq()
    {
            cout<<head->data;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;queue obj;
    cin>>n;
    while(n--)
    {

        int q;
        cin>>q;
        switch(q)
        {
            case 1: int data;cin>>data;obj.enqueue(data);break;
            case 2: obj.dequeue();break;
            case 3: obj.printq();break;

        }
    }

    return 0;
}
