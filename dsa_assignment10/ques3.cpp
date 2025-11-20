#include <iostream>
#include<list>
#include <queue>
using namespace std;
class graph {
    int V;
    list<int>*l;
    public :
    graph(int v) {
        V=v;
        l=new list<int>[V];
    }
void addedge(int u, int v) {
    l[u].push_back(v);
     l[v].push_back(u);
}
void display () {
    for(int i=0;i<V; i++) {
        cout<<i<<"->";
        for(int neighbour: l[i]) {
            cout<<neighbour<<" ";
        }
            cout<<endl;
        }
    }

    void dfshelper(int u, bool vis[]) {
        vis[u]=true;
        cout<<u<<" ";
            for(int v : l[u]) {
             if(!vis[v]) {
                dfshelper(v,vis);
             }   
    }}

    void dfs(int u) {
        bool vis[V]={false};
        dfshelper(u,vis);
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
 g.dfs(1);
return 0;
}