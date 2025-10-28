# include <iostream>
using namespace std;
int arr[100], n = 0;
void create() {
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
    cin >> arr[i];
}
void display() {
    for (int i = 0; i < n; i++)
     cout << arr[i] << " ";
    cout << "\n";
}
void insert() {
    int pos, val;
if(n==0) {
    create();
}
    else {
    cout << "Enter position and value: ";
    cin >> pos >> val;
    for (int i = n; i > pos - 1; i--)
     arr[i] = arr[i - 1];
    arr[pos - 1] = val;
    n++;}}

void remove() {
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    for (int i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}
void linearSearch() {
    int key;
    cout << "Enter value: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at position " << i + 1 << "\n";
            return;
        }
    }
    cout << "Not found\n";
}
int main () {
   int i;
    
        cout << "\n---MENU---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
       do{  cout << "Enter choice: ";
        cin >> i;
        switch (i) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: remove(); break;
            case 5: linearSearch(); break;
    case 6: cout<<"end";
        }
    } while(i!=6);



    return 0;
}
