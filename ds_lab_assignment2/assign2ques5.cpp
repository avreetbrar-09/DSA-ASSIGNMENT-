#include <iostream>
using namespace std;

class diagonal {
    int n; int *a;
public:
    diagonal(int n) { this->n=n; a=new int[n]; }
    void set(int i,int j,int v) { if(i==j) a[i-1]=v; }
    int get(int i,int j) { if(i==j) return a[i-1]; return 0; }
};

class tridiag {
    int n; int *a;
public:
    tridiag(int n) { this->n=n; a=new int[3*n-2]; }
    void set(int i,int j,int v) {
        if(i-j==1) a[i-2]=v;
        else if(i==j) a[n-1+i-1]=v;
        else if(j-i==1) a[2*n-1+i-1]=v;
    }
    int get(int i,int j) {
        if(i-j==1) return a[i-2];
        if(i==j) return a[n-1+i-1];
        if(j-i==1) return a[2*n-1+i-1];
        return 0;
    }
};

class lower {
    int n; int *a;
public:
    lower(int n) { this->n=n; a=new int[n*(n+1)/2]; }
    int idx(int i,int j) { return i*(i-1)/2 + (j-1); }
    void set(int i,int j,int v) { if(i>=j) a[idx(i,j)] = v; }
    int get(int i,int j) { if(i>=j) return a[idx(i,j)]; return 0; }
};

class upper {
    int n; int *a;
public:
    upper(int n) { this->n=n; a=new int[n*(n+1)/2]; }
    int idx(int i,int j) { return j*(j-1)/2 + (i-1); }
    void set(int i,int j,int v) { if(i<=j) a[idx(i,j)] = v; }
    int get(int i,int j) { if(i<=j) return a[idx(i,j)]; return 0; }
};

class symmetric {
    int n; int *a;
public:
    symmetric(int n) { this->n=n; a=new int[n*(n+1)/2]; }
    int idx(int i,int j) {
        if(i>=j) return i*(i-1)/2 + (j-1);
        return j*(j-1)/2 + (i-1);
    }
    void set(int i,int j,int v) { a[idx(i,j)] = v; }
    int get(int i,int j) { return a[idx(i,j)]; }
};

int main() {
    diagonal d(4);
    tridiag t(4);
    lower l(4);
    upper u(4);
    symmetric s(4);
}
