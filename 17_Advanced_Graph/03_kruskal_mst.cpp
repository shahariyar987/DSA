#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

class DSU {
    vector<int> parent;
    vector<int> rankValue;

public:
    DSU(int n) {
        parent.resize(n);
        rankValue.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (rankValue[a] < rankValue[b])
            swap(a, b);

        parent[b] = a;

        if (rankValue[a] == rankValue[b])
            rankValue[a]++;

        return true;
    }
};

bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<Edge> graph(edges);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < edges; i++)
        cin >> graph[i].u
            >> graph[i].v
            >> graph[i].weight;

    sort(graph.begin(), graph.end(), compareEdge);

    DSU dsu(vertices);

    int totalWeight = 0;
    int selectedEdges = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (const Edge& edge : graph) {
        if (dsu.unite(edge.u, edge.v)) {
            cout << edge.u << " - "
                 << edge.v << " : "
                 << edge.weight << "\n";

            totalWeight += edge.weight;
            selectedEdges++;

            if (selectedEdges == vertices - 1)
                break;
        }
    }

    if (selectedEdges != vertices - 1) {
        cout << "Graph is disconnected. MST cannot be formed.\n";
    } else {
        cout << "Total MST weight = "
             << totalWeight << "\n";
    }

    return 0;
}
