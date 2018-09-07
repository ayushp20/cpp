#include<iostream>
using namespace std;
struct node
{
    int a;
    node *next;
    node *prev;
};

class list
{
    node *head;
    node *tail;
public:
    list()
    {
        head=tail=NULL;
    }
    void push();
    void pop(int n);
    void disp();

};

void list::push()
{
    node *n=new node;
    cout<<"\n Enter Integer :";
    cin>>n->a;
    if(head==NULL)
    {
        head=n;
        n->prev=NULL;
        tail=n;
        n->next=NULL;
    }
    else
    {n->prev=tail;
    tail->next=n;
    tail=n;
    n->next=NULL;
    }
}
void list::disp()
{
    for(node *t=head;t!=NULL;t=t->next)
        cout<<t->a;
}

void list::pop(int temp)
{
    int i=0;
    node *n;
    if(temp==1&&head==tail)
    {
        n=head;
        cout<<"Last entry deleted";
        delete n;
        head=tail=NULL;

    }
    else{

    for(n=head;i<temp-1;i++)
        n=n->next;

    node *t,*p;

    if(n==tail)
    {
        tail=n->prev;
        tail->next=NULL;
        delete n;
    }
    else if (n==head)
    {
        head=n->next;
        head->prev=NULL;
        delete n;
    }
    else if(head==tail)
    {
    }
    else
    {
    t=n->next;
    p=n->prev;
    t->prev=p;
    p->next=t;
    delete n;
    }
    }

}
int main()
{
    list obj;
    int ch;char ch1;
    do{
            cout<<"Enter Choice : ";
    cin>>ch;
    switch(ch)
    {case 1:obj.push();break;
     case 2:{cout<<"Enter Object No. :";cin>>ch;obj.pop(ch);break;}
     case 3:obj.disp();break;

    }
    cout<<"\n Do You Wish to continue?";
    cin>>ch1;
}while(ch1=='y');
    return 0;
}
