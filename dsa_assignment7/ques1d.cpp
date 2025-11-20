#include <iostream>
using namespace std;
void merge(int arr[],int s,int e,int mid) {
    int i=s;
    int j=mid+1;
    int temp[e-s+1];
    int k=0;
    while(i<=mid && j<=e) {
        if(arr[i]>arr[j]) {
        temp[k++]=arr[j];
        j++;
    
        }
        else if(arr[i]<arr[j]) {
        temp[k++]=arr[i];
        i++;
        }
    }
    while(i<=mid) {
  temp[k++]=arr[i];
        i++;
    }
    while(j<=e) {
  temp[k++]=arr[j];
        j++;
    }
 k=0;
    for(int i=s;i<=e;i++) {
        arr[i]=temp[k++];
    }
}
void mergesort(int arr[],int s,int e) {
    if(s>=e) {
        return;
    }
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e,mid);
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
mergesort(arr,0,5);
print (arr,6);
return 0;
}