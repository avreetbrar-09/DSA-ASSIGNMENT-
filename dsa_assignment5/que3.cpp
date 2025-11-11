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
    void mid () {
        if(head==NULL) {
            return ;
        }
        node *fast=head;
        node *slow=head;
        while(  fast!=NULL && fast->next!=NULL ) {
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<slow->data<<endl;
        return ;
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
cout <<" middle of ll is : " ;
 s.mid();
return 0;
}