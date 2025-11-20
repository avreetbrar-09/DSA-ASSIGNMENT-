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

    void bfs() {
        queue<int>q;
        bool visited[V]={false};
        q.push(0);
        visited[0]=true;
        while(q.size()>0) {
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(int v : l[u]) {
                if(!visited[v]) {
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
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
 g.bfs();
return 0;
}