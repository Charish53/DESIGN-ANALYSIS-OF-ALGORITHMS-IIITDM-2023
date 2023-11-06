/*implementation of bfs*/
#include<bits/stdc++.h>
using namespace std;
void bfs(int s, vector<int> g[], vector<bool> &vis, int N)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : g[u])
        {
            if(!vis[v])
            {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}
int disconnected(vector<int> g[], vector<bool> &vis, int N) 
{
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        if(!vis[i])
        {
            count++;
            bfs(i, g, vis, N);
        }
    }
    return count;
}
int main()
{
    int N, E;
    cin >> N >> E;
    vector<int> g[N];
    vector<bool> vis(N, false); // Initialize vis array here
    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // For undirected graphs, you need to add edges in both directions
    }
    bfs(0, g, vis, N);
    cout << endl;
    //cout << disconnected(g, vis, N) << endl; //no of connected components
    return 0;
}
