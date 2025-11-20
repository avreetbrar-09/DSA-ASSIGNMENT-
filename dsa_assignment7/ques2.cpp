#include <iostream>
using namespace std;

void selectionsort(int arr[],int n) {
for(int i=0;i<n/2;i++) {
    int min=i;
    int max=n-1-i;
    if(arr[min]>arr[max]) {
        swap(arr[max],arr[min]);
    }
    for(int j=i+1;j<n-i-1;j++) {
        if(arr[min]>arr[j]) {
            min=j;
        }
        if(arr[max]<arr[j]) {
            max=j;
        }
    }
    swap(arr[min],arr[i]);
    if(max==i) {
        max=min;
    }
    swap(arr[max],arr[n-i-1]);
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