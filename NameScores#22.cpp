#include<iostream>
using namespace std;

struct node
{
    string name;
    int nameScore;
    node*left;
    node*right;
};

class BST
{
    node*root;
public:
    bst()
    {
        root=NULL;
    }

    node *createnode(string newName)
    {
        node*info=new node;
        info->name=newName;
        int temp=0;
        for(int i=0;i!='\0';i++)
        {
            temp+=newName[i]-'A'+1;
        }
        info->nameScore=temp;
        info->left=info->right=NULL;
    }
    void insertnode(string newName)
    {
        node*temp=createnode(newName);

        if(root==NULL)
            root=temp;
        else
        {

        }
    }
};

int main()
{
    BST tree;

    return 0;
}
