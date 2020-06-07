#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vi> graph;
 
int n, m;
graph grafo, kika;
vi t, temp;
 
bool comp(int a, int b) {
	return a > b;
}
 
int main() {
	//ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
	cin >> n >> m;
	int in1, in2;
	grafo.assign(n + 5, vi());
	kika.assign(n + 5, vi());
	t.assign(n + 5, 0);
	temp.assign(n + 5, 1);
	for (int i = 0; i < m; i++) {
		cin >> in1 >> in2;
		grafo[in1].push_back(in2);
		grafo[in2].push_back(in1);
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i + 1];
		kika[t[i + 1]].push_back(i + 1);
	}
	vi ans;
	ans.reserve(n);
	for (int i = 1; i <= n; i++) {
		for (int j : kika[i]) {
			for (int v : grafo[j]) {
				if (temp[v] == temp[j]) temp[v]++;
			}
			ans.push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (temp[i] != t[i]) {
			cout << "-1\n";
			return 0;
		}
	}
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}