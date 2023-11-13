#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix (0 or 1):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    for (int v1 = 0; v1 < n; ++v1) {
        for (int v2 = 0; v2 < n; ++v2) {
            for (int v3 = 0; v3 < n; ++v3) {
                for (int v4 = 0; v4 < n; ++v4) {
                    if (v1 != v2 && v2 != v3 && v3 != v4 && v4 != v1 && v1 != v3 && v2 != v4) {
                        if (graph[v1][v2] && graph[v2][v3] && graph[v3][v4] && graph[v4][v1]) {
                            cout << "C4 found: " << v1 << " " << v2 << " " << v3 << " " << v4 << endl;
                            cout << "Graph contains a C4." << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "Graph does not contain a C4." << endl;
    return 0;
}
