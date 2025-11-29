#include <iostream>
using namespace std;

int h[100], n = 0;

void insertPQ(int x) {
    n++;
    int i = n;
    h[i] = x;
    while(i > 1 && h[i/2] < h[i]) {
        swap(h[i], h[i/2]);
        i = i/2;
    }
}

int deletePQ() {
    int x = h[1];
    h[1] = h[n];
    n--;
    int i = 1, j = 2*i;
    while(j <= n) {
        if(j < n && h[j] < h[j+1]) j++;
        if(h[i] < h[j]) {
            swap(h[i], h[j]);
            i = j;
            j = 2*i;
        } else break;
    }
    return x;
}

void display() {
    for(int i = 1; i <= n; i++) cout << h[i] << " ";
    cout << endl;
}

int main() {
    int ch, x;
    while(true) {
        cin >> ch;
        if(ch == 1) {
            cin >> x;
            insertPQ(x);
        }
        else if(ch == 2) cout << deletePQ() << endl;
        else if(ch == 3) display();
        else break;
    }
}