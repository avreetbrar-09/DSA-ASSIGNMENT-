#include <iostream>
using namespace std;

int main() {
    int a[10][10], trans[10][10];
    int r, c;

    cout << "Enter rows and cols: ";
    cin >> r >> c;
int sum[r+c];
    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
for(int i=0; i<c; i++) {
    sum[i]=0;
    for(int j=0; j<r; j++) {
        sum[i]+=a[i][j];
    }
}
for(int i=0; i<c; i++) {
    sum[r+i]=0;
    for(int j=0; j<r; j++) {
        sum[r+i]+=a[j][i];
    }
}
for(int i=0; i<r+c; i++) {
    cout<<sum[i]<<" ";
}
return 0;
}