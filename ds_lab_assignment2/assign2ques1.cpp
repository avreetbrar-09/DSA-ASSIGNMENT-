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
    int target;
    cout<<"enter element to search : ";
    cin>>target;
int st=0, end=n-1;
while(st<=end) {
    int mid=st+(end-st)/2;
    if(arr[mid]==target) {
        cout<<"the element you searched for is at index :"<<mid;
        break;
    }
    else if(target >arr[mid]) {
        st=mid+1;
    }
      else if(target <arr[mid]) {
        end=mid-1;
    }
}
  
    return 0;

}