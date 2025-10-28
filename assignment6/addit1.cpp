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
 void pushfront(int val) {
    node *newnode=new node(val);
    if(isempty()) {
        head=tail=newnode ;
        tail->next=head;
    }
    else {
      newnode->next=head;
      head=newnode;
      tail->next=newnode; 
    }
 }

 void pushback (int val) {
       node *newnode=new node(val); 
    if(isempty()) {
        head=tail=newnode;
    tail->next=head;
    }
    else {
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
 }

 void insert(int val, int pos) {
    if(head==NULL) {
        return;
    }
    else {
        int count =1;
        node *temp=head;
        while(temp->next!=head && count <=pos-1) {
            count ++;
            temp=temp->next;
        }
        
        if(temp->next==head) {
            return;
        }
        else {
            node *newnode=new node(val);
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
 }
 void pop(int pos) {
    if(isempty()) {
        return;
    }
    else {

        if(pos==1) {
            tail->next=head->next;
            head=head->next;
            return;
        }
        node *temp=head;
        int count=1;
        while(temp->next!=head && count <pos-1) {
temp=temp->next;
count++;
        }
        if(temp->next==head) {
            return;
        }
        if(temp->next==tail) {
          temp->next=head;
          tail=temp;
          return;  
        }
        temp->next=temp->next->next;
        }

 }

 void search(int key) {
if(isempty()) {
    return;
}
node *temp=head;
 int count=0;
do {
    temp=temp->next;
    count++;
 }  while(temp!=head && temp->data!=key);
 if(temp->data==key ) {
    cout<<"the key is found at : "<< count <<endl ;
    return;
 }
 else {
    cout<<"key not found "<<endl;
 }
 }

 void display () {
    if(isempty()) {
        cout<<"empty"<<endl;
        return;
    }
    node*temp=head;
do {
        cout<<temp->data<<"->";
                temp=temp->next;
    }     while(temp!=head);
    cout<<head->data<<endl;
 }

 pair<node*, node*> halves() {
    if(isempty() || head->next==head) {
        return make_pair(head,head);
    }
    node*fast=head;
    node*slow=head;
    while(fast->next!=head && fast->next->next!=head) {
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast->next->next==head) {
        fast=fast->next;
    }
    node*head1=head;
    node*head2=slow->next;
    slow->next=head1;
    fast->next=head2;
    display(head1);
    display(head2);
    return make_pair(head1,head2);
 }
 void display(node* h) {
    if(h==NULL) {
        return;
    }
    node*temp=h;
    do {
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=h);
    cout<<h->data<<endl;
 }
};

int main() {
circularll c;
c.pushfront(20);
c.pushback(10);
c.pushback(30);
c.insert(5,2);
c.display();
c.halves();
return 0;
}