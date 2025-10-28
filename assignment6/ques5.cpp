#include <iostream>
using namespace std;
class node {
    public :
    node *next;
    int data;
    node(int val) {
        data=val;
        next=NULL;
    }
};
class circularll{
    node*head;
    node *tail;
    public :
    circularll()
 {
    head=tail=NULL;
 }

 bool isempty() {
    return head==NULL;
 }

 bool iscircular() {
    if(isempty()) {
        return true;
    }
    node*temp=head->next;
    while(temp!=NULL && temp!=head) {
        temp=temp->next;
    }
    return (temp==head);
 }
};