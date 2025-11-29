#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findp(int x, vector<int> &p) {
    if (p[x] == x) return x;
    return p[x] = findp(p[x], p);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){ return a.w < b.w; });
    vector<int> parent(n + 1), rankv(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;
    int mst_w = 0;
    vector<Edge> mst;
    for (auto e : edges) {
        int x = findp(e.u, parent);
        int y = findp(e.v, parent);
        if (x != y) {
            if (rankv[x] < rankv[y]) parent[x] = y;
            else if (rankv[y] < rankv[x]) parent[y] = x;
            else { parent[y] = x; rankv[x]++; }
            mst_w += e.w;
            mst.push_back(e);
        }
    }
    cout << "Weight " << mst_w << endl;
    for (auto e : mst) cout << e.u << " " << e.v << " " << e.w << endl;
    return 0;
}
