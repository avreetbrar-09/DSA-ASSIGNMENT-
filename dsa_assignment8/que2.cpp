/*Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)
(b) Maximum element of the BST
(c) Minimum element of the BST
(d) In-order successor of a given node the BST
(e) In-order predecessor of a given node the BST*/
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
bool search(node* root, int key) {
    if(root==NULL) {
return false;
    }
    if(root->data==key) {
        return true;
    }
    if(root->data>key) {
        return search(root->left,key);
    }
    else if(root->data<key){
       return search(root->right,key);
    }
    return false;
}
static int idx=0;
 void inorder(node*root, int arr[]) {
if(root== NULL) {
    return;
}
inorder(root->left,arr);
arr[idx++]=root->data;
inorder(root->right,arr);
}
bool searchwithoutres(node*root,int key) {
    if(root==NULL) {
        return false;
    }
    int arr[100];
    idx=0;
    inorder(root, arr);
    int st=0;
    int end=idx-1;
    while(st<=end){
        int mid=(st+end)/2;
    if(arr[mid]==key) {
        return true;
    }
    if(arr[mid]>key) {
        end=mid-1;
    }
    if(arr[mid]<key) {
        st=mid+1;
    }}
    return false;
}

int maxelement(node*root) {
    if(root==NULL) {
        return 0;
    }
    if(root->right==NULL) {
      return root->data;
    }
     return  maxelement(root->right);
}
int minelement(node*root) {
    if(root==NULL) {
        return 0;
    }
    if(root->left==NULL) {
      return root->data;
    }
     return  minelement(root->left);
}
int inorderSuccessor(node* root, int key) {
    if (root == NULL) return -1;
    int arr[100];
    idx = 0;
    inorder(root, arr);

    for (int i = 0; i < idx; i++) {
        if (arr[i] == key) {
            if (i + 1 < idx) 
                return arr[i + 1];
            else
                return -1;
        }
    }
    return -1; 
}


int inorderPredecessor(node* root, int key) {
    if (root == NULL) return -1;
    int arr[100];
    idx = 0;
    inorder(root, arr);

    for (int i = 0; i < idx; i++) {
        if (arr[i] == key) {
            if (i - 1 >= 0) 
                return arr[i - 1];
            else
                return -1; 
        }
    }
    return -1; 
}
int main() {
 node * root= new node(3);
root->left=new node(2);
root->right=new node(9);
root->left->left=new node(1);
root->right->left=new node(8);
cout<<search(root,1);
cout<<searchwithoutres(root,4);
cout<<maxelement(root);
cout<<minelement(root);
cout<<inorderSuccessor(root,9);
cout<<inorderPredecessor(root,3);
return 0;
}