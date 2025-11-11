# include <iostream>
using namespace std;


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
void heapsort(int arr[], int n) {
    int i=n;
    for(int i=n/2-1; i>=0 ; i--) {
        heapify(i,arr,n);
    }
     i=n;
    while(i>1) {
        swap(arr[0],arr[i-1]);
        i--;
        heapify(0,arr,i);
    }
}

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[]={20,10,5,7,15,25};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    print (arr,n);
}