/* Write a program to determine whether a given binary tree is a BST or not.
*/
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
bool validate (node *root,node* min,node* max) {
    if(root==NULL) {
        return true;
    }
    if(min!=NULL && root->data<min->data) {
        return false;
    }
    if(max !=NULL && root->data>max->data) {
        return false;
    }
return validate(root->left,min,root) && validate(root->right,root,max);  
}

int main() {
   node * root= new node(3);
root->left=new node(2);
root->right=new node(9);
root->left->left=new node(1);
root->right->left=new node(8);
cout<<validate(root,NULL,NULL);  
}