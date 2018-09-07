#include <iostream>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* parent;
    long long sum;
}

Node* newNode(int key){
    Node* info = new Node;
    info->key = key;
    info->left = NULL;
    info->right = NULL;
    info->sum = (long long)key;

    return info;
}
long long getSum(Node* root){

    if(root == NULL)
        return (long long)0;

    return root->sum;
}

Node* rightRotate(Node* y){

    Node* x = y->left;

    y->left = x->right;
    x->right->parent = y;

    x->right = y;
    y->parent = x;

    return x;

}

Node* leftRotate(Node* y){

    Node* x = y->right;

    y->right = x->left;
    x->left->parent = y;

    x->left = y;
    y->parent = x;

    return x;

}

Node* splay(int key){

    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree
    if (root->key > key)
    {


    }

}

Node* insertNode(int key){

    if(root == NULL){
        root = newNode(key);
    }

    else if(key < root->key){
        root->left = insertNode(root->left, key);
        root->left->parent = root;
    }
    else if(key > root->key){
        root->right = insertNode(root->right, key);
        root->right->parent = root;
    }
    root = splay(root);
    root->sum = (long long)root->key + getSum(root->left) + getSum(root->right);

    return root;
}

Node* findNode(int key){

    if(root == NULL)
        return root;


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



