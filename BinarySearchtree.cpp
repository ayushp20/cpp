#include<iostream>
using namespace std;
struct node
{
    int data;
    node *lchild;
    node *rchild;
};
node *NewNode(int item)
{
    node *temp=new node;
    temp->data=item;
    temp->lchild=temp->rchild=NULL;
    return temp;
}
node *insert(node *node ,int key)
{
    if(node==NULL)
        return NewNode(key);
    if(key>node->data)
        node->rchild=insert(node->rchild,key);
    if(key<node->data)
        node->lchild=insert(node->lchild,key);
    return node;
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        cout<<root->data<<" ";
        inorder(root->rchild);
    }
}

int main()
{
    node *root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,60);

    inorder(root);

}
