#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adj;

public:
    Graph(int v) {
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int neighbor : adj[i])
                cout << neighbor << " ";
            cout << "\n";
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u >= 0 && u < vertices && v >= 0 && v < vertices)
            graph.addEdge(u, v);
        else {
            cout << "Invalid vertex. Try again.\n";
            i--;
        }
    }

    graph.display();

    return 0;
}
