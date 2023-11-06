#include <iostream>
#include <queue>

using namespace std;

const int MAX_V = 100; 

void addEdge(bool adjMatrix[MAX_V][MAX_V], int u, int v) {
    adjMatrix[u][v] = true;
    adjMatrix[v][u] = true; 
}

bool BFS(bool adjMatrix[MAX_V][MAX_V], int V, int start, bool visited[MAX_V]) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    int distance[MAX_V];
    for (int i = 0; i < V; i++) {
        distance[i] = -1;
    }
    distance[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
                distance[v] = distance[u] + 1;
            } else if (adjMatrix[u][v] && distance[v] == distance[u]) {
                return true; 
            }
        }
    }

    return false; 
}

bool hasOddCycle(bool adjMatrix[MAX_V][MAX_V], int V) {
    bool visited[MAX_V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (BFS(adjMatrix, V, i, visited)) {
                return true;
            }
        }
    }

    return false; 
}

int main() {
    int V, E; 
    cin >> V >> E;

    bool adjMatrix[MAX_V][MAX_V] = {false};

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adjMatrix, u, v);
    }

    if (hasOddCycle(adjMatrix, V)) {
        cout << "The graph contains an odd cycle." << endl;
    } else {
        cout << "The graph does not contain an odd cycle." << endl;
    }

    return 0;
}

