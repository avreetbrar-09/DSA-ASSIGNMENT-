#include <iostream>
using namespace std;
int main() {
    int rows, cols, t;
    cout << "Enter number of rows and columns for first matrix : ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements for first matrix: ";
    cin >> t;
    int matrix1[t][3];
    int r,c,val;
    cout<<"enter row, column and value for non zero elements of first matrix :";
    for(int i=0; i<rows ;i++) {
cin>>r>>c>>val;
    }
    for(int i=0; i<rows; i++) {
    matrix1[i][0]=r;
    matrix1[i][1]=c;
    matrix1[i][2]=val;
    }
      for(int i=0; i<rows; i++) {
  for(int j=0; j<3; j++) {
 cout<<matrix1[i][j];
    }
    }
    return 0;
}
