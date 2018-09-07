#include <iostream>
#include <cstdio>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* parent;
    long long sum;
    int height;
};

//Node creation utility
Node* newNode(int key){

    Node* info = new Node;
    info->key = key;
    info->left = NULL;
    info->right = NULL;
    info->parent = NULL;
    info->height = 0;
    info->sum = (long long)key;

    return info;
}

int height(Node* node){

    if(node == NULL)
        return -1;

    return node->height;
}

//get balance
int getBalance(Node* root){

    if(root == NULL)
        return 0;

    return height(root->left)- height(root->right);
}

long long getSum(Node* root){

    if(root == NULL)
        return (long long)0;

    return root->sum;
}
Node* leftRotate(Node* y){

    Node* x = y->right;
    Node* temp = x->left;

    x->left = y;
    y->right = temp;


    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    y->sum = (long long)y->key + getSum(y->left) + getSum(y->right);
    x->sum = (long long)x->key + getSum(x->left) + getSum(x->right);


    return x;
}

Node* rightRotate(Node* y){

    Node* x = y->left;
    Node* tmp = x->right;

    x->right = y;
    y->left = tmp;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    y->sum = (long long)y->key + getSum(y->left) + getSum(y->right);
    x->sum = (long long)x->key + getSum(x->left) + getSum(x->right);

    // Return new root
    return x;
}

Node* insertNode(Node* root, int key){


    //Normal BST insertion
    if(root == NULL)
        return newNode(key);

    if(key < root->key){
        root->left = insertNode(root->left, key);

    }
    else if(key > root->key){
        root->right = insertNode(root->right, key);

    }

    //Update Height of Ancestor
    root->height = 1 + max(height(root->left), height(root->right));


    //Get Balance
    int balance = getBalance(root);


    //if unbalanced,

    //left - left
    if(balance > 1 && key < root->left->key)
        return rightRotate(root);

    //left-right
    if(balance > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //right - right
    if(balance < -1 && key > root->right->key)
        return leftRotate(root);

    // right - left
    if(balance < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    root->sum = (long long)root->key + getSum(root->left) + getSum(root->right);
    return root;

};
Node* minValueNode(Node* root){

    Node* temp = root;

    while(temp->left != NULL)
        temp = temp->left;

    return temp;
}

Node* deleteNode(Node* root, int key){

    //not found
    if(root == NULL)
        return root;
    //find in left subtree
    if(key < root->key)
        root->left = deleteNode(root->left, key);
    //find in right subtree
    else if(key > root->key)
        root->right = deleteNode(root->right, key);

    else{
         //Node with 1 child or No child
        if(root->left == NULL || root->right == NULL){
            Node* temp = root->left? root->left : root->right;

            //No Child Case
            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            delete temp;
        }

         //2 child case
         else{

            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
         }
    }

    if(root == NULL)
        return root;

    root->height= 1+ max(height(root->left), height(root->right));

    int balance = getBalance(root);

    //if unbalanced,

    //left - left
    if(balance > 1 && key < root->left->key)
        return rightRotate(root);

    //left-right
    if(balance > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //right - right
    if(balance < -1 && key > root->right->key)
        return leftRotate(root);

    // right - left
    if(balance < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    root->sum = (long long)root->key + getSum(root->left) + getSum(root->right);

    return root;

}

bool findNode(Node* root, int key){

    if(root == NULL)
        return false;

    if(key < root->key)
        return findNode(root->left, key);

    else if(key > root->key)
        return findNode(root->right, key);

    return true;
}


long long rangeSum(Node* root, int l, int r){

    if(root == NULL)
        return (long long)0;

    if(root->key >= l && root->key <= r){
        return (long long)root->key + rangeSum(root->left,l,r) + rangeSum(root->right, l, r);
    }

    else if(l > root->key)
        return rangeSum(root->right,l,r);

    if(root->key > r)
        return rangeSum(root->left,l,r);

    return (long long)0;

}
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root){
    if(root != NULL)
    {
        cout<<root->key<<" "<<"("<<root->sum<<") ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

const int MODULO = 1000000001;
/* Drier program to test above function*/
int main()
{
    int n;
    Node * root = NULL;
    scanf("%d", &n);
    int last_sum_result = 0;
    for (int i = 0; i < n; i++) {
        char buffer[10];
        scanf("%s", buffer);
        char type = buffer[0];
        switch (type) {
        case '+': {
            int x;
            scanf("%d", &x);
            root = insertNode(root, (x + last_sum_result) % MODULO);
        } break;
        case '-': {
            int x;
            scanf("%d", &x);
            root = deleteNode(root, (x + last_sum_result) % MODULO);
        } break;
        case '?': {
            int x;
            scanf("%d", &x);
            printf(findNode(root, (x + last_sum_result) % MODULO) ? "Found\n" : "Not found\n");
        } break;
        case 's': {
            int l, r;
            scanf("%d %d", &l, &r);
            long long res = rangeSum(root, (l + last_sum_result) % MODULO, (r + last_sum_result) % MODULO);
            printf("%lld\n", res);
            last_sum_result = int(res % MODULO);
        }
        }
    }
    return 0;
}
