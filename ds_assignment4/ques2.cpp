/*Develop a menu driven program demonstrating the following operations on Circular 
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/

#include<iostream>
using namespace std;

class cqueue {
    public:
     int f,r ,size,capacity;
     int *arr;
cqueue (int n) {
  capacity = n;
        arr = new int[capacity];
        f = 0;
        r = -1;
        size = 0;
 }
 void push(int val) {
if(size==capacity) {
    cout<<"queue is full"<<endl;
    return;
}
else {
    r=(r+1)%capacity;
    arr[r]=val;
size++;
}
 }

 void pop() {

    if(size==0) {
        cout<<"queue is empty"<<endl;
        return ;
    }
    else f=(f+1)%capacity;
    size--;
 }

 bool empty() {
    return size==0;
 }

 bool isfull() {
    return size==capacity;
 }

 void peek() {
    if(size==0) {
        cout<<"queue is empty"<<endl;

    }
    else {
        cout<<arr[f]<<endl;
    }
 }

 void display() {
    if(size==0) {
        cout<<"queue is empty"<<endl;
        return;
    }
    int i=0;

    while(i<size) {
        cout<<arr[(f+i)%capacity]<<" ";
        i++;
    }
 }
};

int main() {
cqueue q(5);
int choice, val;


do {

    cout<<"operations are : "<<endl;
cout << "1. Enqueue\n";
cout << "2. Dequeue\n";
cout << "3. Peek\n";
cout << "4. Display\n";
cout << "5. Check if Empty\n";
cout << "6. Check if Full\n";
cout << "0. Exit\n";
cout<<"enter choice : "<<endl;
cin>>choice;
switch(choice) {
          case 1:
                cout << "Enter value: ";
                cin >> val;
                q.push(val);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.empty() ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;
            case 6:
                cout << (q.isfull() ? "Queue is Full" : "Queue is not Full") << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
}
while(choice !=0);
    return 0;
}