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
class sll {

    public :
        node *head;
    sll() {
        head=NULL;
    }
    void deleteatgivenpt(int key) {
        if (head == NULL) 
    return;
        if (head->data == key) {
         node *h=head;
         head=head->next;
         delete h;
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
void count(int key) {
    if(head==NULL) {
        return;
    }
    int count=0;
    node *temp=head;
    while(temp) {
        if(temp->data ==key) {
            count++;
             deleteatgivenpt(key) ;

        }
        temp=temp->next;
    }
cout<<"count :"<<count <<endl;
void print();
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
       sll s;
    s.head = new node(1);
    s.head->next = new node(2);
    s.head->next->next = new node(1);
    s.head->next->next->next = new node(2);
    s.head->next->next->next->next = new node(1);
    s.head->next->next->next->next->next = new node(3);
    s.head->next->next->next->next->next->next = new node(1);

    cout << "Original list: ";
    s.display();

    s.count(1);

    cout << "After deleting all 1's: ";
    s.display();
}
