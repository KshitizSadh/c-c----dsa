#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


    int u, v, weight;
};


struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

      
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

   
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    DSU dsu(V);

    vector<Edge> mst; 
    int totalWeight = 0;

  
    for (auto &edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    cout << "\nMinimum Spanning Tree edges:\n";
    for (auto &edge : mst) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << "\n";
    }

    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
