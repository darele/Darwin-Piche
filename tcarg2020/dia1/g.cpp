#include <bits/stdc++.h>
#define vi vector <int>
#define graph vector <vi>

using namespace std;

int n, k;
graph grafo;
vi p, d;

void dfs(int u) {
    for (int v : grafo[u]) {
        if (v != p[u]) {
            p[v] = u;
            d[v] = d[u] + 1;
            dfs(v);
        }
    }
}

void calldfs(int s){
    p.assign(n, 0);
    d.assign(n, 0);
    dfs(s);
}

int hoja(int s) {
    calldfs(s);
    int mayor = 0;
    int indice;
    for (int i = 0; i < n; i++) {
        if (d[i] > mayor) {
            mayor = d[i];
            indice = i;
        }
    }
    return indice;
}

int centro(int hoja) {
    vi cola;
    cola.reserve(n);
    while (p[hoja]) {
        cola.push_back(hoja);
        hoja = p[hoja];
    }
    return (cola[cola.size() / 2]);
}

void solve() {
    if (n < 4) {
        cout << "No\n";
        return;
    }
    n += 5;
    int c = centro(hoja(hoja(1)));
    calldfs(c);
    int mayor = 0;
    bool band = 1;
    for (int i = 0; i < n; i++) {
        if (grafo[i].size() == 1) {
            if (d[i] != k) band = false;
        }
        if (grafo[i].size() && i != c) {
            grafo[i].resize(grafo[i].size() - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (grafo[i].size()) {
            if (grafo[i].size() < 3) band = false;
        }
    }
    cout << (band ? "Yes" : "No");
}

int main() {
    cin >> n >> k;
    int in1, in2;
    grafo.assign(n + 5, vi() );
    for (int i = 1; i < n; i++) {
        cin >> in1 >> in2;
        grafo[in1].push_back(in2);
        grafo[in2].push_back(in1);
    }
    solve();
    return 0;
}