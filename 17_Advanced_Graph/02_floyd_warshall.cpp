#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 1000000000;

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<vector<int>> dist(
        vertices, vector<int>(vertices, INF)
    );

    for (int i = 0; i < vertices; i++)
        dist[i][i] = 0;

    cout << "Enter number of directed weighted edges: ";
    cin >> edges;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        if (weight < dist[u][v])
            dist[u][v] = weight;
    }

    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] =
                        dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "\nAll-pairs shortest path matrix:\n";

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF)
                cout << setw(6) << "INF";
            else
                cout << setw(6) << dist[i][j];
        }
        cout << "\n";
    }

    return 0;
}
