#include <iostream>
using namespace std;

struct tnode{
    int data;
    tnode* left;
    tnode* right;
};
tnode* root = NULL;
class tree{
public:
    void insert_(tnode* node, int i){
    if(node == NULL){
        node = new tnode;
        (node)->left = NULL;
        (node)->right = NULL;
        (node)->data = i;
        root = node;
        return;
    }
    else{
        if(i < node->data)
            insert_(node->left,i);
        if(i > (node)->data)
            insert_((node)->right,i);
        return;

    }
}
void func(tnode* node){
    if(node != NULL){
        func((node)->left);
        tnode *temp;
        temp = (node)->left;
        (node)->left = (node)->right;
        (node)->right = temp;
        func((node)->right);
    }
}
void traverse(tnode* node){
    if(node!=NULL){
        traverse(node->left);
        traverse(node->right);
        cout<<(node)->data<<endl;
    }
}
};

int main(){
    tree*bt = new tree;
    bt->insert_(root,98);
    bt->insert_(root,15);
    bt->insert_(root,100);
    bt->insert_(root,10);
    bt->insert_(root,78);
    bt->insert_(root,120);
    bt->insert_(root,5);
    bt->insert_(root,12);
    bt->insert_(root,96);
    bt->insert_(root,110);
    bt->insert_(root,99);
    bt->traverse(root);
}
