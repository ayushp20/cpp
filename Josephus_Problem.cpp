#include<iostream>
#include<string.h>
using namespace std;
struct node
{
    char ch[20];
    node *link;

};
class list
{
    node *head,*tail;
public:
    list()
    {
        head=tail=NULL;
    }
    void push()
    {
       node *n=new node;
       cout<<"Enter Name : ";
       cin>>n->ch;
       if(head==NULL)
       {
           n->link=NULL;
           head=tail=n;
       }
       else
       {
           tail->link=n;
           tail=n;
           tail->link=head;
       }
    }
    void pop(int n, node *start)
    {
        node *t;
        int i=1;
        if(head==NULL)
        {
            cout<<"Empty Queue";
        }
        else
        {
            for(t=start;t!=NULL;t=t->link,i++)
        {
            if(i==n-1)
            {
                cout<<"Removed"<<t->ch<<endl;
                start=t->link;
            if(t->link==tail)
            {
                t=tail;
            }
                t->link=(t->link)->link;
                t=t->link;
                delete t;
                return;
            }
            else if(t->link==NULL)
            {
                cout<<t->ch;
                return;
            }
        }
        }
    }

    node *find(char ch[20])
    {
        node *n=head;
        for(int i=0;i<5;i++,n=n->link)
        {
            if(strcmp(ch,n->ch)==0)
            {
                cout<<"Found";
                return n;
            }

        }
    }

};


int main()
{
    list obj;
    int i,n;
    for(i=0;i<5;i++)
        obj.push();
    char ch[20];
    cout<<"Enter The Value of n : ";
    cin>>n;
    cout<<"Enter the Name to Start :";
    cin>>ch;

    node *temp=obj.find(ch);
    i=0;
    while(i<5)
    {
     obj.pop(n,temp);
     i++;
    }
    return 0;
}
