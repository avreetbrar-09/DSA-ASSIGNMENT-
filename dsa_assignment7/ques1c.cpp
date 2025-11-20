#include <iostream>
using namespace std;
void bubblesort(int arr[],int n) {
    for(int i=0;i<n;i++) {
       bool Swap=false;
       for(int j=0;j<n-i-1;j++) {
        if(arr[j]>arr[j+1]) {
            swap(arr[j],arr[j+1]) ;
            Swap=true;
        }
       }
       if(!Swap) {
        return;
       }
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
bubblesort(arr,6);
print (arr,6);
return 0;
}