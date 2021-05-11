#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
} node;



node *createNode(int data) {
    node * root = new node;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}



int height(node *root) {
    if(!root)
        return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

int getBalance(node *root){
    return height(root->left) - height(root->right);
} 



node *rightRotate(node *root) {
    node * t = root->left;
    node * u = t->right;
    t->right = root;
    root->left = u;
    return t;
}


node *leftRotate(node *root) {
    node * t = root->right;
    node * u =  root->right->left;
    root->right->left = root;
    //u must be put root->right, because u > root
    root->right = u;
    //cat diretcly reutrn root->right, because root->right be changed
    return t;
}



node *minValue(node *root) {
    if(!root)
        return NULL;
    while(root->left){
        root = root->left;
    }
    return root;
}


node *insert(node *root, int item) {
    if(!root){
        return createNode(item); 
    }
    if(item <= root->data){
       root->left = insert(root->left, item); 
    }
    else if(item > root->data){
        root->right = insert(root->right, item);
    }
    int b = getBalance(root);
    if(b < -1){
        if(getBalance(root->right) > 0){
           //RL
           root->right = rightRotate(root->right);
        }
        //RR
        root = leftRotate(root);
    }
    else if(b > 1){
        if(getBalance(root->left) < 0){
            //LR
            root->left = leftRotate(root->left); 
        }
        //LL
        root =  rightRotate(root);
    }
    return root;
}



node *deleteNode(node *root, int key) {
    //recursive need terminate condition
    if(!root)
        return NULL;
    if(key<root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key>root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(!root->left) {
            node * tmp = root->right;
            delete root;
            return tmp;
        }
        else if(!root->right){
            node * tmp = root->left;
            delete root;
            return tmp;
        }
        node *tmp = minValue(root->right);
        root->data = tmp->data;
        //important
        root->right = deleteNode(root->right, tmp->data);
    }
    return root;
}

void print_tree(node * root){
    queue<node*> q;
    int c = -1;
    q.push(root);
    int step = 1;
    while(!q.empty()){
        c++;
        root = q.front(); q.pop();
        if(!root)
            printf("null ");
        else{
            printf("%d ", root->data);
            q.push(root->left);
            q.push(root->right);
        }
        if(c%step == 0){
            c = 0;
            step *= 2;
            printf("\n");
        }
    }
    printf("\n\n");
}

int main() {
    node * root = NULL;
    for(int i=0;i<10;i++){
        root = insert(root, i);
    }
    print_tree(root);
    printf("delete 3\n");
    root = deleteNode(root, 3);
    print_tree(root);
}

