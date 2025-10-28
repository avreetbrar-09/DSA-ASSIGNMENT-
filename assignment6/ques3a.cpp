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
 void pushfront(int val) {
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

 void pushback (int val) {
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

 void insert(int val, int pos) {
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
 void pop(int pos) {
    if(isempty()) {
        return;
    }
    else {
        node *temp=head;
        int count=1;
        while(temp!=NULL && count <pos) {
temp=temp->next;
count++;
        }
        if(temp==NULL) {
            return;
        }
        else {
            if(temp==head) {
head=head->next;
if(head!=NULL) {
head->prev=NULL;}
else {
tail=NULL;
delete temp;
return;}
            }
            if(temp==tail) {
                tail=tail->prev;
                if(tail!=NULL)
                tail->next=NULL;
                else 
             head=NULL;
             delete temp;
             return;
            }
            else {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                temp->next=NULL;
                temp->prev=NULL;
                delete temp;
            }
        }
    }
 }

 

 void size() {
    if(isempty()) {
        cout<<"ll is empty"<<endl;
        return;
    }
    int count=0;
    node*temp=head;
    while(temp!=NULL) {
        count++;
        temp=temp->next;
    }
    cout<<"size of ll is : "<<count<<endl;
 }
};
int main() {
    doublyll c;
c.pushfront(20);
c.pushback(10);
c.pushback(30);
c.insert(5,2);
c.size();
return 0;
}