#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) if (!vis[v]) {
            vis[v] = 1;
            q.push(v);
        }
    }
    cout << endl;
    return 0;
}
