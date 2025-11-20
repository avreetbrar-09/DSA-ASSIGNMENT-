#include <iostream>
#include<vector>
using namespace std;
class graph {
    int V;
    vector<int>adj[20];
    public :
    graph(int v) {
        V=v;
    }
void addedge(int u, int v) {
    adj[u].push_back(v);
     adj[v].push_back(u);
}
void display () {
    for(int i=0;i<V; i++) {
        cout<<i<<"->";
        for(int neighbour: adj[i]) {
            cout<<neighbour<<" ";
        }
            cout<<endl;
        }
    }
int degree(int v) {
    return adj[v].size();
}
void adjacentvertiice(int v) {
    for(int x: adj[v]) {
        cout<<x<<" ";
      
    }
     cout<< endl;
}
int noofedges() {
    int count=0;
    for(int i=0; i<V;i++) {
        count+=adj[i].size();
    }
    return count/2;
}
};

int main() {
    int V, E;
    cout<<"Enter no of vertices : ";
    cin>>V;
    graph g(V);
    cout<<"enter no of edges : ";
 cin>>E;
 cout<<"enter pair of edges :";
 for(int i=0; i<E; i++) {
    int u,v;
    cin>>u>>v;
    g.addedge(u,v);
 }
 g.display();
 cout<<g.noofedges()<<endl;
g.adjacentvertiice(3);
cout<<g.degree(2)<<endl;
return 0;
}