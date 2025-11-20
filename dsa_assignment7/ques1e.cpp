#include <iostream>
using namespace std;
int  partition(int arr[],int s,int e) {
  int  i=s-1;
  int pivot=arr[e];
for(int j=s; j<e;j++){
if(arr[j]<=pivot) {
    i++;
    swap(arr[i],arr[j]);
}
}
i++;
swap(arr[i],arr[e]);
return i;
}
void quicksort(int arr[],int s,int e) {
    if(s>=e) {
        return;
    }
    int pivotidx=partition(arr,s,e);
    quicksort(arr,s,pivotidx-1);
    quicksort(arr,pivotidx+1,e);
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
quicksort(arr,0,5);
print (arr,6);
return 0;
}