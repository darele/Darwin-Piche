#include <bits/stdc++.h>
#define tam 200005

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <int, int> ii;
typedef vector <dl> vii;
typedef vector <vi> graph;

vi p;
graph grafo;
vector <bool> v, ev;
vl precio;
vi indices;
vii temp;
bitset <tam> vis;

bool comp(int a, int b) {
	return precio[a] < precio[b];
}

void dfs2(int u) {
	for (int v : grafo[u]) {
		if (v != p[u]) {
			p[v] = u;
			dfs2(v);
		}
	}
}

void dfs(int u) {
	vis[u] = 1;
	for (int x : grafo[u]) {
		if (x != p[u] && !vis[x]) {
			dfs(x);
		}
		if (x != p[u]) {
			temp[u].first += temp[x].first;
			temp[u].second += temp[x].second;
		}
	}
	if (v[u] != ev[u]) {
		if (ev[u]) temp[u].second++;
		else temp[u].first++;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	p.assign(n + 5, 0);
	grafo.assign(n + 5, vi ());
	precio.resize(n + 1);
	indices.resize(n + 1);
	v.resize(n + 1);
	ev.resize(n + 1);
	temp.resize(n + 1);
	temp[0] = {0, 0};
	int in1, in2, in3;
	for (int i = 1; i <= n; i++) {
		temp[i] = {0, 0};
		indices[i] = i;
		cin >> in1 >> in2 >> in3;
		precio[i] = in1;
		v[i] = in2;
		ev[i] = in3;
	}
	sort(indices.begin(), indices.end(), comp);
	for (int i = 1; i < n; i++) {
		cin >> in1 >> in2;
		grafo[in1].push_back(in2);
		grafo[in2].push_back(in1);
	}
	dfs2(1);
	vis.reset();
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		in1 = indices[i];
		if (vis[in1]) continue;
		dfs(in1);
		ll x = min(temp[in1].first, temp[in1].second);
		ll result = 2 * x * precio[in1];
		ans += result;
		temp[in1].first -= x;
		temp[in1].second -= x;
	}
	if (temp[1].first == 0 && temp[1].second == 0) cout << ans << "\n";
	else cout << "-1\n";
	return 0;
}
