#include "list.h"
using namespace std;

void list::push()
{
    node *info=new node;
    cout<<"Enter integer : ";
    cin>>info->a;

    info->link=top;
    top=info;
}
 void list::display()
 {
     if(top==NULL)
        cout<<"Underflow";
     else{
        for(node *t=top;t!=NULL;t=t->link)
            cout<<t->a<<" ";
     }
 }

