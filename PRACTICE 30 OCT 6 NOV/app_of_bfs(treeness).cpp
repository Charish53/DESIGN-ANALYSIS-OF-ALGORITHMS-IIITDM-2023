/*checking for tree using bfs*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    Graph(int V);
    void addEdge(int u, int v);
    int countConnectedComponents();
    void BFS(int start, vector<bool>& visited);

private:
    int V;
    vector<vector<int>> adj;
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

void Graph::BFS(int start, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int Graph::countConnectedComponents() {
    vector<bool> visited(V, false);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            BFS(i, visited);
            count++;
        }
    } 

    return count;
}

int main() {
    int V, E; 
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int connectedComponents = g.countConnectedComponents();
    cout << "Number of connected components: " << connectedComponents << endl;
    if(connectedComponents==1&&(E-V+1)==0)
    cout<<"Tree";
    else
    cout<<"Not a Tree";
    
    return 0;
}

