#include<iostream>
using namespace std;
int main() {
        int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int b[n];
for( int i=0; i<n; i++) {
 b[i]=i+1;
}
for(int i=0; i<n; i++) {
    if(arr[i]!=b[i]) {
        cout<<"missing element is : "<< b[i];
        break;
    }
}

    return 0;}