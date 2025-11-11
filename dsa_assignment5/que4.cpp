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

    void reverse() {
        node *temp=head;
        node *prev=NULL;
        node *next=NULL;
        while(temp!=NULL) {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        } 
        head=prev;
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
    s.head->next->next = new node(3);
    s.head->next->next->next = new node(4);
    s.head->next->next->next->next = new node(5);
    s.reverse();
    s.display();
    return 0;
}