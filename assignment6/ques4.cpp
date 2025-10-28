#include <iostream>
using namespace std;
class node {
    public :
    node *next;
    node *prev;
    int data;
    node(int val) {
        data=val;
        next=prev=NULL;
    }
};
class doublyll{
    node*head;
    node *tail;
    public :
    doublyll()
 {
    head=tail=NULL;
 }

 bool isempty() {
    return head==NULL;
 }
 void pushfront(char val) {
    node *newnode=new node(val);
    if(isempty()) {
        head=tail=newnode ;
    }
    else {
      newnode->next=head;
      head->prev=newnode;
      head=newnode;
      head->prev=NULL;  
    }
 }

 void pushback (char val) {
       node *newnode=new node(val); 
    if(isempty()) {
        head=tail=newnode ;
    }
    else {
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
        tail->next=NULL;
    }
 }

 void insert(char val, int pos) {
    if(head==NULL) {
        return;
    }
    else {
        int count =1;
        node *temp=head;
        while(temp!=NULL && count <=pos-1) {
            count ++;
            temp=temp->next;
        }
        if(temp==NULL) {
            return;
        }
        else {
            node *newnode=new node(val);
            newnode->next=temp->next;
            newnode->prev=temp;
            if(temp->next!=NULL) {
                temp->next->prev=newnode;
                temp->next=newnode;
            }
        
        }
    }
 }

 void palindrome() {
    if(isempty()) {
        return;
    }
    if(head==tail) {
        cout<<"it is palindrome"<<endl;
    }
    node*temp1=head;
    node*temp2=tail;
    while(temp1!=temp2 && temp1->prev!=temp2) {
if(temp1->data!=temp2->data) {
    cout<<"not a palindrome"<<endl;
    return;
}
temp1=temp1->next;
temp2=temp2->prev;
    }
    cout<<"it is a valid palindrome"<<endl;
 }
};
int main() {
    doublyll c;
c.pushfront('a');
c.pushback('b');
c.pushback('a');
c.insert('b',2);
c.palindrome();
return 0;
}