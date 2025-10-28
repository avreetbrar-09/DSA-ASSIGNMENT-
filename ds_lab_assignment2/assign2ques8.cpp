#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main() {
        int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

map <int,int> m;
  int count=0;
  for(int i=0; i<n; i++) {
    if (m.find(arr[i])==m.end()) {
m[arr[i]]++;
count++;
    }
    else {
        count--;
    }
  }
  cout<<"total unique numbers in the array : "<<count;
    return 0;
}