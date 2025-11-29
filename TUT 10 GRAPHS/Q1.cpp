#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjMat(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjList[u].push_back(v);
    }
    while (true) {
        int ch;
        cout << "1 Adjacency Matrix\n2 Adjacency List\n3 Degree(in/out) of vertex\n4 Adjacent vertices of vertex\n5 Number of edges\n6 Exit\n";
        cin >> ch;
        if (ch == 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) cout << adjMat[i][j] << " ";
                cout << endl;
            }
        } else if (ch == 2) {
            for (int i = 1; i <= n; i++) {
                cout << i << ":";
                for (int v : adjList[i]) cout << " " << v;
                cout << endl;
            }
        } else if (ch == 3) {
            int v;
            cin >> v;
            int outdeg = 0, indeg = 0;
            for (int j = 1; j <= n; j++) if (adjMat[v][j]) outdeg++;
            for (int i = 1; i <= n; i++) if (adjMat[i][v]) indeg++;
            cout << "Outdegree=" << outdeg << " Indegree=" << indeg << endl;
        } else if (ch == 4) {
            int v;
            cin >> v;
            for (int u : adjList[v]) cout << u << " ";
            cout << endl;
        } else if (ch == 5) {
            int edges = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (adjMat[i][j]) edges++;
            cout << edges << endl;
        } else break;
    }
    return 0;
}
