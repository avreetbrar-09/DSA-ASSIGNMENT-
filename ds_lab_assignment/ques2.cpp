# include <iostream>
using namespace std;

void create(int arr[],int &n) {
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    int i;
    for (i = 0; i < n; i++) 
    cin >> arr[i];
}
int main() {
    int arr[100];
    int n;
    
     create (arr,n);
     
     for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
                 if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];  
                }
                n--; 
                j--; 
            }
        }
    }
     
     cout<<"final array with unique elements : ";
      for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
      }
     return 0;
}