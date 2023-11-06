/*implementation of dfs*/
#include<bits/stdc++.h>
using namespace std;
void dfs(int s, vector<int> g[], vector<bool> &vis, int N)
{
    vis[s] = true;
    cout << s << " ";
    for(int v : g[s])
    {
        if(!vis[v])
        {
            dfs(v, g, vis, N);
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
            dfs(i, g, vis, N);
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
    dfs(0, g, vis, N);
    cout << endl;
    //cout << disconnected(g, vis, N) << endl; //no of connected components
    return 0;
}
