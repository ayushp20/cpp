/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack <int> s;
    int n,x,t;
    cin>>n;
    while(n--){
        cin>>t;
        if(t==1){
            cin>>x;
            if(s.empty())
              s.push(x);
             else
              s.push(max(x,s.top()));
        }
        else if(t==2){
                 if (!s.empty())
                     s.pop();
        }
         if(t==3){
             cout<<s.top()<<endl;

        }

    }
    return 0;
}
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
  long int data;
  node *prev;
};
class list
{node *top;
 public:
    list()
    {
        top=NULL;
    }
void push(int n)
{
    node *info=new node;
    info->data=n;
    info->prev=top;
    top=info;
}
void pop()
{
    node *t=top;
    top=t->prev;
    delete t;
}
void display()
{
    long int max=top->data;
    node *t=top;
    while(t!=NULL)
    {
        if(t->data > max)
        {
            max=t->data;
        }
        t=t->prev;
    }
    cout<<max<<endl;
}
};
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

int main() {

    long int n,i=0,ch,ch1;
    list obj;
    cin>>n;

    while(i!=n)
    {
        cin>>ch;
        switch(ch)
        {
            case 1: cin>>ch1;obj.push(ch1);break;
            case 2: obj.pop();break;
            case 3: obj.display();
        }
        i++;
    }
    return 0;
}
