/*. Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,
(c) Maximum depth of BST
(d) Minimum depth of BST*/
#include <iostream>
using namespace std;
class node {
    public:
    node*left;
    node*right;
    int data;
    node(int val) {
        data=val;
        left=right=NULL;
    }
};

node * insert (node * root, int key) {
    if(root==NULL){
    return new node(key);
 }
 if(key<root->data) {
root->left =insert(root->left,key);
 }
 if(key>root->data) {
root->right =insert(root->right,key);
 }
 return root;
}

node * inoreder(node* root) {
    while(root!=NULL && root->left!=NULL) {
        root=root->left;
    }
    return root;
}

node* deleteelem(node *root,int key) {
if(root==NULL) {
    return NULL;
}
if(key<root->data) {
    root->left=deleteelem(root->left,key);
}
if(key>root->data) {
    root->right=deleteelem(root->right,key);
}
if(key==root->data) {
    if(root->left==NULL) {
        node*temp=root->right;
        delete root;
        return temp;
    }
    else if(root->right==NULL) {
        node*temp=root->left;
        delete root;
        return temp;
    }
    else {
        node *Insuc=inoreder(root->right);
        root->data=Insuc->data;
        root->right=deleteelem(root->right,Insuc->data);
    }
}
return root;
}



int maxdepth(node * root) {
    if(root==NULL) {
return 0;
    }
   int leftht= maxdepth(root->left);
  int  rightht= maxdepth(root->right);
  return max(leftht,rightht)+1;
}
int mindepth(node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return 1 + mindepth(root->right);

    if (root->right == NULL)
        return 1 + mindepth(root->left);

    int leftDepth = mindepth(root->left);
    int rightDepth = mindepth(root->right);

    if (leftDepth < rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

int main () {
    node *root=NULL;
root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);

cout<<maxdepth(root);
cout<<mindepth(root);
return 0;

}