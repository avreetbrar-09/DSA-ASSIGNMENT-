#include<iostream>
#include <queue>
using namespace std;
class stack{
    queue<int> q;
    queue<int> q2;
    int val;
public:
void push(int x) {
    if(q.empty()) {
q.push(x);}
else {
while(!q.empty()) {
q2.push(q.front());
q.pop();
}
q.push(x);
while(!q2.empty()) {
    q.push(q2.front());
    q2.pop();
}
}
}
void pop() {
       if (q.empty()) {
            cout << "Stack is empty\n";
            return;}
    q.pop();
}

void top() {
       if (q.empty()) {
            cout << "Stack is empty\n";
        return ;}
  cout<<  q.front();
}
bool empty() {
    return q.empty();
}

void display() {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
}
};
int main() {
    stack s;
    s.push(2);
    s.push(6);
    s.push(7);
    s.display();
    return 0;
}