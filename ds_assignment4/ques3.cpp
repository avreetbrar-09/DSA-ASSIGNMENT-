#include<iostream>
#include <queue>
using namespace std;
class intermix {
    public:
intermix(queue <int> &q) {
    int n=q.size();
int size=q.size()/2;
queue<int>q2;
for(int i=0; i<size; i++) {
    q2.push(q.front());
    q.pop();
}

queue<int>q1;
while(q.size()!=0 && q2.size()!=0) {
    q1.push(q2.front());
    q2.pop();
    q1.push(q.front());
    q.pop();
}
if(q.size()!=0) {
    while(!q.empty())
     q1.push(q.front());
    q.pop();
}
if(q2.size()!=0) {
    while(!q2.empty())
     q1.push(q2.front());
    q2.pop();
}
while(!q1.empty()) {
    cout<<q1.front()<<" ";
    q1.pop();
}
}
};

int main() {
queue<int> q;
q.push(4);
q.push(7);
q.push(11);
q.push(20);
q.push(5);
q.push(9);
intermix q1(q);
return 0;
}