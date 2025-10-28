#include<iostream>
#include <queue>
using namespace std;
class stack{
    queue<int> q;
    queue<int> q2;
    int val;
public:
void push(int x) {
int n=q.size();
q.push(x);
for(int i=0; i<n; i++) {
    q.push(q.front());
    q.pop();
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