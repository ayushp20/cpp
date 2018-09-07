#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
};
class BST
{
    Node *root;
public:
    BST()
    {
        root=NULL;
    }

    Node*getroot()
    {
        return root;
    }
    Node* createnode(int key)
    {
        Node* temp=new Node;
        temp->data=key;
        temp->lchild=temp->rchild=NULL;
        return temp;
    }
    void insertnode(int key,Node* ptr)
    {
        if(root==NULL)
        {
            root=createnode(key);
        }
        else
        {
            if(key<ptr->data)
            {
                if(ptr->lchild==NULL)
                    ptr->lchild=createnode(key);
                else
                    insertnode(key,ptr->lchild);
            }
            else
            {
                if(ptr->rchild==NULL)
                    ptr->rchild=createnode(key);
                else
                    insertnode(key,ptr->rchild);
            }
        }
    }

    void display(Node*ptr)
    {
        if(ptr!=NULL)
        {
            display(ptr->lchild);
            display(ptr->rchild);

            cout<<ptr->data<<" ";
        }
    }
    Node* searchnode(int key,Node*ptr)
    {
        if(ptr!=NULL)
        {
            if(key==ptr->data)
                return ptr;
            else

                {
                   if(key<ptr->data)
                        ptr->lchild=searchnode(key,ptr->lchild);
                   else
                        ptr->rchild=searchnode(key,ptr->rchild);
                }
        }
        else
            cout<<"Key not found!";
            return NULL;
    }

    Node* minvaluenode(Node*ptr)
    {
        Node*current=ptr;
        while(current->lchild!=NULL)
            current=current->lchild;

        return current;
    }

    Node* delnode(int key,Node*ptr)
    {
        if(ptr==NULL)
            return ptr;
        if(key<ptr->data)
            ptr->lchild=delnode(key,ptr->lchild);
        else if(key>ptr->data)
            ptr->rchild=delnode(key,ptr->rchild);
        else
        {
            if(ptr->lchild==NULL)
            {
                Node*temp=ptr->lchild;
                free(ptr);
                return temp;
            }
            else if(ptr->rchild==NULL)
            {
                Node*temp=ptr->rchild;
                free(ptr);
                return temp;
            }
            Node*temp=minvaluenode(ptr->rchild);
            ptr->data=temp->data;
            ptr->rchild=delnode(temp->data,ptr->rchild);
        }
        return ptr;

    }
    void func(Node* node){
    if(node != NULL){
        func(node->lchild);
        Node *temp = node->lchild;
        node->lchild = node->rchild;
        node->rchild = temp;
        func(node->rchild);
    }
}
};

int main()
{
    BST bt;
    bt.insertnode(98,bt.getroot());
    bt.insertnode(15,bt.getroot());
    bt.insertnode(100,bt.getroot());
    bt.insertnode(10,bt.getroot());
    bt.insertnode(78,bt.getroot());
    bt.insertnode(120,bt.getroot());
    bt.insertnode(5,bt.getroot());
    bt.insertnode(12,bt.getroot());
    bt.insertnode(96,bt.getroot());
    bt.insertnode(110,bt.getroot());


    bt.func(bt.getroot());
    bt.insertnode(99,bt.getroot());

    bt.display(bt.getroot());
    return 0;

}
