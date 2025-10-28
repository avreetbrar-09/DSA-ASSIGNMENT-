#include<iostream>
using namespace std;
int main() {
        int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter  elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
for( int i=0; i<n; i++) {
    for(int j=0; j<n-i-1; j++) {
        if(arr[j]>arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
}
cout << "sorted array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;}