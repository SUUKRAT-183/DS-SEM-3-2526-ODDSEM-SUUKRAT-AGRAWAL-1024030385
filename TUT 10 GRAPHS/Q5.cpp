#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    const int INF = 1000000000;
    vector<vector<int>> w(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        if (wt < w[u][v]) {
            w[u][v] = wt;
            w[v][u] = wt;
        }
    }
    vector<int> key(n + 1, INF), parent(n + 1, -1), inMST(n + 1, 0);
    int start = 1;
    key[start] = 0;
    for (int c = 1; c <= n; c++) {
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u])) u = i;
        inMST[u] = 1;
        for (int v = 1; v <= n; v++)
            if (w[u][v] < INF && !inMST[v] && w[u][v] < key[v]) {
                key[v] = w[u][v];
                parent[v] = u;
            }
    }
    int total = 0;
    for (int v = 1; v <= n; v++) if (parent[v] != -1) total += w[v][parent[v]];
    cout << "Weight " << total << endl;
    for (int v = 1; v <= n; v++)
        if (parent[v] != -1) cout << parent[v] << " " << v << " " << w[v][parent[v]] << endl;
    return 0;
}
