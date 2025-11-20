#include <iostream>
using namespace std;
void insertionsort(int arr[],int n) {
    for(int i=1;i<n;i++) {
       int curr=arr[i];
       int prev=i-1;
       while(prev>=0 && arr[prev]>curr) {
        arr[prev+1]=arr[prev];
        prev--;
       }
       arr[prev+1]=curr;
    }
}

void print(int arr[],int n) {
    for(int i=0; i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
int arr[6]={2,4,1,5,3,6};
cout<<"Before sorting :";
print(arr,6);
cout<<"After sorting : ";
insertionsort(arr,6);
print (arr,6);
return 0;
}