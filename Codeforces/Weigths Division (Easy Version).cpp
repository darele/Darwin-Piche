/*
https://codeforces.com/problemset/problem/1399/E1
*/

#include <bits/stdc++.h>
#define ll uint64_t
#define ii pair <int, ll>
#define dl pair <ll, int>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vii>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)

using namespace std;

int n;
graph grafo;
vi p;
vl hojas;
vl peso;
ll suma;
set <dl> cola;

ll dif(int u) {
    return peso[u] * hojas[u] - (peso[u] / 2) * hojas[u];
}

void dfs(int u) {
    if (grafo[u].size() == 1) {
        hojas[u] = 1;
    }
    for (ii v : grafo[u]) {
        if (v.first == p[u]) continue;
        p[v.first] = u;
        peso[v.first] = v.second;
        dfs(v.first);
        hojas[u] += hojas[v.first];
    }
    suma += (hojas[u] * peso[u]);
    cola.insert({dif(u), u});
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll s;
        cin >> n >> s;
        grafo.assign(n + 1, vii());
        hojas.assign(n + 1, 0);
        peso.assign(n + 1, 0);
        p.assign(n + 1, 0);
        cola.clear();
        suma = 0;
        int in1, in2, in3;
        REP(0, n - 1) {
            cin >> in1 >> in2 >> in3;
            grafo[in1].push_back({in2, in3});
            grafo[in2].push_back({in1, in3});
        }
        dfs(1);
        int cont = 0;
        while (suma > s) {
            dl temp = *cola.rbegin();
            cola.erase(temp);
            suma -= dif(temp.second);
            peso[temp.second] >>= 1;
            cola.insert({dif(temp.second), temp.second});
            cont++;
        }
        cout << cont << "\n";
    }
    return 0;
}
