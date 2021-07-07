#include <bits/stdc++.h>
#define inf 1000000005

using namespace std;

typedef vector <int> vi;
typedef vector <vi> graph;

int n, m, l;
graph grafo;
vector <bool> vis;

void bfs() {
    queue <int> cola;
    vis.assign(n + 5, 0);
    for (int i = 0; i < l; i++) {
        int x;
        cin >> x;
        cola.push(x);
        vis[x] = 1;
    }
    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        for (int v : grafo[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                cola.push(v);
            }
        }
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
        bfs();
        int cont = 0;
        for (int i = 0; i < n + 5; i++) {
            if (vis[i]) cont++;
        }
        cout << cont << "\n";
    }
    return 0;
}