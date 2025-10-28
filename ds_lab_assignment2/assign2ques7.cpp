#include<iostream>
using namespace std;
int inversion (int arr[],int n) {
    int count=0;
for(int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
if(arr[i]>arr[j]) {
    count ++;
}
    }
}
return count;
}
int main() {
        int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout<< "number of inversion is :"<< inversion(arr,n);
    return 0;
}