/*
https://codeforces.com/contest/1338/problem/B
*/

#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)

using namespace std;

int n;
graph grafo;
vi p, d;
int cont, r;

void dfs(int u) {
    bool band = (p[u] != r);
    for (int v : grafo[u]) {
        if (v == p[u]) continue;
        p[v] = u;
        d[v] = d[u] + 1;
        if (grafo[v].size() == 1) {cont += band; band = false;}
        else cont++;
        dfs(v);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    int in1, in2;
    grafo.assign(n + 1, vi());
    p.assign(n + 1, 0);
    d = p;
    REP(1, n) {
        cin >> in1 >> in2;
        grafo[in1].push_back(in2);
        grafo[in2].push_back(in1);
    }
    REP(1, n + 1) {
        if (grafo[i].size() == 1) {
            cont = 0;
            r = i;
            dfs(i);
            break;
        }
    }
    int ans = 1;
    REP(1, n + 1) {
        if (grafo[i].size() == 1) {
            if (d[i] % 2) ans = 3;
        }
    }
    cout << ans << " ";
    cout << cont << "\n";
    return 0;
}
