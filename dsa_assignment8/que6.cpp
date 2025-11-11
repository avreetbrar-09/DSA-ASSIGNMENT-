#include <iostream>
using namespace std;
class priorityq {
    int arr[100];
    int n=0;
    public :
    void push(int val) {
n++;
int i=n-1;
arr[i]=val;
int paridx=(i-1)/2;
while(paridx>=0 && arr[paridx]<arr[i]) {
    swap(arr[paridx],arr[i]);
    i=paridx;
    paridx=(i-1)/2;
}
    }

    int top() {
        return arr[0];
    }

    bool empty() {
        return n==0;
    }

    void pop() {
        swap(arr[0],arr[n-1]);
        n--;
        heapify(0,arr,n);
    }
    void heapify(int i, int arr[], int n) {
    int left=2*i+1;
    int right=2*i+2;
    int maxidx=i;
    if(left<n && arr[maxidx]<arr[left]) {
        maxidx=left;
    }
    if(right<n && arr[maxidx]<arr[right]) {
        maxidx=right;
    }
    if(maxidx!=i) {
        swap(arr[i],arr[maxidx]);
        heapify(maxidx,arr,n);
    }
}
void print() {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}
};

int main() {
    priorityq pq;
    pq.push(5);
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(40);
    pq.push(20);
    pq.print();
    pq.pop();
    pq.pop();
       pq.print();
    return 0;
}