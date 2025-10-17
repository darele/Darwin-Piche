#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define dl pair<ll, ll>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<dl>
#define graph vector<vi>
#define LIM 100005

using namespace std;

// int p[LIM];
// int rank[LIM];

// int getSet(int u) {return u == p[u] ? u : p[u] = getSet(p[u]);}

// int merge(int u, int v) {
// 	int x = getSet(u);
// 	int y = getSet(v);
// 	if (x == y) {
// 		return true;
// 	}
// }

graph grafo;
bitset<LIM> vis;
int indegree[LIM];
int n, m;

bool dag() {
	queue<int> cola;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			cola.push(i);
		}
	}
	while (!cola.empty()) {
		int u = cola.front();
		cola.pop();
		vis[u] = true;
		for (int i = 0; i < grafo[u].size(); i++) {
			int v = grafo[u][i];
			if (vis[v]) return false;
			indegree[v]--;
			if (indegree[v] == 0) {
				cola.push(v);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (indegree[i] > 0) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin >> n >> m;
	grafo.assign(n + 5, vi());
	int a, b;
	vi copyIndegree(n, 0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		grafo[a].push_back(b);
		indegree[b]++;
		copyIndegree[b]++;
		if (!dag()) {
			cout << i + 1 << endl;
			return;
		}
		for (int i = 0; i < n; i++) {
			indegree[i] = copyIndegree[i];
		}
		vis.reset();
	}
	cout << -1 << endl;
}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}