#include <iostream>
#include<list>
#include <queue>
using namespace std;
class graph {
    int V;
    list<pair<int,int>>*l;
    public :
    graph(int v) {
        V=v;
        l=new list<pair<int,int>>[V];
    }
void addedge(int u, int v,int w) {
    l[u].push_back({v, w});
    l[v].push_back({u, w});
}
    void prims(int start = 0) {
        bool selected[100] = {false};
        selected[start] = true;

        cout << "MST edges";
        for (int count = 0; count < V - 1; count++) {
            int u = -1, v = -1, minWeight = 100000;
            for (int i = 0; i < V; i++) {
                if (selected[i]) {           
                    for (auto nbr : l[i]) {
                        int node = nbr.first;
                        int wt = nbr.second;

                        if (!selected[node] && wt < minWeight) {
                            minWeight = wt;
                            u = i;
                            v = node;
                        }
                    }
                }
            }
            selected[v] = true;
            cout << u << " -- " << v << "   weight = " << minWeight << endl;
        }
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
    int u,v,w;
    cin>>u>>v>>w;
    g.addedge(u,v,w);
 }
return 0;
}