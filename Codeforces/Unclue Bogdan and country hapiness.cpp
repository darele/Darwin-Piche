/*
https://codeforces.com/contest/1388/problem/C
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
#define tam 1000001

using namespace std;

int n, m;
graph grafo;
vl per, gente, h, malo;
vi p;
bool band;

void dfs(int u) {
	for (int v : grafo[u]) {
		if (v == p[u]) continue;
		p[v] = u;
		dfs(v);
		per[u] += per[v];
	}
	if (abs(h[u]) > per[u]) band = false;
	if (((per[u] - h[u]) & 1) == 0) {
		malo[u] = ((per[u] - h[u]) >> 1);
		ll temp = 0;
		for (int v : grafo[u]) {
			if (v == p[u]) continue;
			temp += malo[v];
		}
		temp += gente[u];
		if (temp < malo[u]) band = false;
	} else band = false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	cin >> n >> m;
    	grafo.assign(n + 1, vi());
    	p.assign(n + 1, 0);
    	per.assign(n + 1, 0);
    	h.assign(n + 1, 0);
    	malo.assign(n + 1, 0);
    	gente.assign(n + 1, 0);
    	band = true;
    	REP(0, n) {cin >> per[i + 1]; gente[i + 1] = per[i + 1];}
    	REP(1, n + 1) cin >> h[i];
    	int in1, in2;
    	REP(0, n - 1) {
    		cin >> in1 >> in2;
    		grafo[in1].push_back(in2);
    		grafo[in2].push_back(in1);
    	}
    	dfs(1);
    	if (band) cout << "YES\n";
    	else cout << "NO\n";
    }
    return 0;
}
