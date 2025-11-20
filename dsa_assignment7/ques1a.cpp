#include <iostream>
using namespace std;

void selectionsort(int arr[],int n) {
for(int i=0;i<n-1;i++) {
    int min=i;
    for(int j=i+1;j<n;j++) {
        if(arr[min]>arr[j]) {
            min=j;
        }
    }
    swap(arr[min],arr[i]);
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
selectionsort(arr,6);
print (arr,6);
return 0;
}