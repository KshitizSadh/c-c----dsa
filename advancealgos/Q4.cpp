#include <iostream>
#include <vector>
#include <climits>

using namespace std;


struct Edge {
    int u, v, weight;
};

int main() {
    int V, E, source;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    cout << "Enter source vertex: ";
    cin >> source;

   
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

   
    bool hasNegativeCycle = false;
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "\nGraph contains a negative weight cycle!" << endl;
    } else {
        cout << "\nShortest distances from source " << source << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To vertex " << i << " = ";
            if (dist[i] == INT_MAX) cout << "INF";
            else cout << dist[i];
            cout << endl;
        }
    }

    return 0;
}
