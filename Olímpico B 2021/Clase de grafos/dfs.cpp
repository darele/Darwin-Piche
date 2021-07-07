#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> graph;

int n, m, l;
graph grafo;
vector <bool> vis;

void dfs(int u) {
    vis[u] = 1;
    for (int v : grafo[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void calldfs() {
    vis.assign(n + 5, 0);
    int x;
    for (int i = 0; i < l; i++) {
        cin >> x;
        dfs(x);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> l;
        vi empty;
        grafo.assign(n + 5, empty);
        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            grafo[x].push_back(y);
        }
        calldfs();
        int cont = 0;
        for (int i = 0; i < n + 5; i++) {
            if (vis[i]) cont++;
        }
        cout << cont << "\n";
    }
    return 0;
}