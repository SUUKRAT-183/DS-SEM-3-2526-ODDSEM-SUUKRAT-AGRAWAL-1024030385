#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<int> &vis) {
    vis[u] = 1;
    cout << u << " ";
    for (int v : adj[u]) if (!vis[v]) dfs(v, adj, vis);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cin >> s;
    vector<int> vis(n + 1, 0);
    dfs(s, adj, vis);
    cout << endl;
    return 0;
}
