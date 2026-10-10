#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    int vertices;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int v) {
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void dijkstra(int source) {
        vector<int> distance(vertices, INT_MAX);
        vector<bool> visited(vertices, false);

        distance[source] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int u = -1;

            for (int i = 0; i < vertices; i++) {
                if (!visited[i] &&
                    (u == -1 || distance[i] < distance[u])) {
                    u = i;
                }
            }

            if (u == -1 || distance[u] == INT_MAX)
                break;

            visited[u] = true;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!visited[v] &&
                    distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }

        cout << "\nShortest distances from vertex " << source << ":\n";

        for (int i = 0; i < vertices; i++) {
            cout << source << " -> " << i << " = ";

            if (distance[i] == INT_MAX)
                cout << "INF";
            else
                cout << distance[i];

            cout << "\n";
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Enter number of weighted edges: ";
    cin >> edges;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        if (u >= 0 && u < vertices &&
            v >= 0 && v < vertices &&
            weight >= 0) {
            graph.addEdge(u, v, weight);
        } else {
            cout << "Invalid edge. Weight must be non-negative.\n";
            i--;
        }
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    if (source >= 0 && source < vertices)
        graph.dijkstra(source);
    else
        cout << "Invalid source vertex.\n";

    return 0;
}
