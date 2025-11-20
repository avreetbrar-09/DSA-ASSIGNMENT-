#include <iostream>
using namespace std;

class matrix {

    int V;
    int adj[100][100];
    public : 
    matrix (int v) {
int adj[v][v];
V=v;
for(int i=0; i<V; i++) {
        for(int j=0; j<V;j++) {
            adj[i][j]=0;
        }
    }
    }
 void setedges(int u, int v) {
    adj[u][v]=1;
    adj[v][u]=1;
 }
  
 void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
 int degree(int v) {
    int deg=0;
    for(int i=0; i<V;i++) {
        if(adj[v][i]==1) {
            deg++;
        }
    }
    return deg;
 }
void adjvertices(int v) {
    cout<< "adjacent vertices of "<<v<<": ";
    for(int j=0; j<V; j++) {
        if(adj[v][j]==1) {
            cout<<j<<" ";
        }
    }
}
int noofedges () {
    int edges=0;
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
edges+= adj[i][j];
        }
    }
    return edges/2;
}
};

int main() {
    int E,V;
    cout<<"enter no of vertices :";
    cin>>V;
    matrix g(V);
 cout<<"enter no of edges : ";
 cin>>E;
 cout<<"enter pair of edges :";
 for(int i=0; i<E; i++) {
    int u,v;
    cin>>u>>v;
    g.setedges(u,v);
 }
 cout<<g.degree(3);
 g.displayMatrix();
 cout << g.noofedges();
 return 0;
}