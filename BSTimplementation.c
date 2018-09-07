#include <iostream>
using namespace std;

struct node
{
    int data;
    node *Lchild,*Rchild;
};
class BSTree
{
    node *root;
public:
    BSTree()
    {
        root=NULL;
    }
    node *insert(node *root, int key)
    {
        node *info=new node;
        info->data=key;
        info->Lchild=NULL;
        info->Rchild=NULL;

        if(root==NULL)
        {
            root=info;
            return root;
        }
        else
        {
            node *tmp=root;
            while(tmp!=NULL)
            {
                if(key<tmp->data)
                {
                    if(tmp->Lchild==NULL)
                        {tmp->Lchild=info;
                         return root;
                        }
                    else
                        tmp=tmp->Lchild;

                }
                else if(key>tmp->data)
                {
                    if(tmp->Rchild=NULL)
                        {tmp->Rchild=info;
                         return root;
                        }
                    else
                        tmp=tmp->Rchild;
                }
            }
        }

    }

    node *search (node *root,int key)
    {

    }

    node *del(node*root,int key)
    {

    }
};
int main()
{

    return 0;
}
