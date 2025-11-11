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
void inorder(node* root) {
if(root== NULL) {
    return;
}

inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
void preorder(node* root) {
if(root== NULL) {
    return;
}
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);
}
void postorder(node* root) {
if(root== NULL) {
    return;
}
postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";
}
int main() {
 node * root= new node(9);
root->left=new node(3);
root->right=new node(1);
root->left->left=new node(2);
root->right->left=new node(8);

inorder(root);
cout<<endl;
preorder(root);
cout<<endl;
postorder(root);
cout<<endl;
return 0;
}