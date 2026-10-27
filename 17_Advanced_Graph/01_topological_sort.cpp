#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices);
    vector<int> indegree(vertices, 0);

    cout << "Enter number of directed edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        order.push_back(current);

        for (int neighbor : graph[current]) {
            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if ((int)order.size() != vertices) {
        cout << "Graph contains a cycle. Topological sorting is not possible.\n";
    } else {
        cout << "Topological order: ";

        for (int vertex : order)
            cout << vertex << " ";

        cout << "\n";
    }

    return 0;
}
