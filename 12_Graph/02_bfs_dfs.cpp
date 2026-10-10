#include <iostream>
#include <vector>
#include <queue>
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

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << "\n";
    }

    void DFSUtil(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << current << " ";

        for (int neighbor : adj[current]) {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(vertices, false);

        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << "\n";
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
            cout << "Invalid edge. Try again.\n";
            i--;
        }
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    if (start >= 0 && start < vertices) {
        graph.BFS(start);
        graph.DFS(start);
    } else {
        cout << "Invalid starting vertex.\n";
    }

    return 0;
}
