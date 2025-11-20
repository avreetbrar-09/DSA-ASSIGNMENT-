#include <iostream>
#include <list>
#include <vector>
using namespace std;

class graph {
    int V;
    list<pair<int,int>> *l;

public:
    graph(int v) {
        V = v;
        l = new list<pair<int,int>>[V];
    }

    void addedge(int u, int v, int w) {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    int minDist(vector<int> &dist, vector<bool> &vis) {
        int m = 1e9, idx = -1;
        for (int i = 0; i < V; i++) {
            if (!vis[i] && dist[i] < m) {
                m = dist[i];
                idx = i;
            }
        }
        return idx;
    }

    void dijkstra(int src) {
        vector<int> dist(V, 1e9);
        vector<bool> vis(V, false);
        dist[src] = 0;

        for (int k = 0; k < V - 1; k++) {
            int u = minDist(dist, vis);
            if (u == -1) break;
            vis[u] = true;

            for (auto p : l[u]) {
                int v = p.first;
                int w = p.second;
                if (!vis[v] && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }

        for (int i = 0; i < V; i++)
            cout << i << " " << dist[i] << endl;
    }
};

int main() {
    int V, E;
    cin >> V;
    graph g(V);

    cin >> E;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addedge(u, v, w);
    }

    int src;
    cin >> src;

    g.dijkstra(src);
    return 0;
}