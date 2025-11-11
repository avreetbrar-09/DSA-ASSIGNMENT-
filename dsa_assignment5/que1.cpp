#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class singlyll {
    node *head;

    public :
singlyll() {
    head=NULL;
}

void insertathead (int val) {
    node *temp=new node (val);
    temp->next=head;
    head=temp;
}
void insertattail(int val) {
    node* newnode = new node(val);
        if (head == NULL) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
        temp = temp->next;}
        temp->next = newnode;
}

void insertbefore (int val,int key) {
    if (head == NULL) 
    return;
        if (head->data == key) {
            insertathead(val);
            return;
        }
        node *temp=head;
        while(temp->next && temp->next->data!=key) {
            temp=temp->next;
        }
        if(temp->next==NULL) {
            return ;
        }
        node * newnode= new node(val);
        newnode->next=temp->next;
        temp->next=newnode;
}

void insertafter(int val,int key) {
    if (head == NULL) 
    return;
        node *temp=head;
        while(temp && temp->data!=key) {
            temp=temp->next;
        }
        if(temp==NULL) {
            return ;
        }
        if(temp->next==NULL) {
            insertattail(val);
        }
        node * newnode= new node(val);
        newnode->next=temp->next;
        temp->next=newnode;
}
void deleteBeg() {
        if (head == NULL) return;
        node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteend() {
        if(head==NULL) {
            return;
        }
        node *temp=head;
while(temp->next->next!=NULL) {
    temp=temp->next;
}
delete(temp->next);
temp->next=NULL;
    }

    void deleteatgivenpt(int key) {
        if (head == NULL) 
    return;
        if (head->data == key) {
            deleteBeg();
            return;
        }
        node *temp=head;
        while(temp->next && temp->next->data!=key) {
            temp=temp->next;
        }
        if(temp->next==NULL) {
            return ;
        }
        node *t=temp->next;
        temp->next=t->next;
        delete(t);
    }
void search(int key) {
        node* temp = head;
        int pos = 1;
        while (temp!=NULL) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found" << endl;
    }
    void display() {
        node* temp = head;
        while (temp!=NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    singlyll ll;
    ll.insertathead(2);
        ll.insertathead(5);
            ll.insertathead(7);
                ll.insertathead(4);
                    ll.insertathead(1);
                   ll.insertattail(20);
                    ll.insertbefore(30,4);
                    ll.display();
                    return 0;
}