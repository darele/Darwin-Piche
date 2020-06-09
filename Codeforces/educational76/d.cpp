#include <bits/stdc++.h>
#define tam 10000010
 
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <set <int> > graph;
 
bool comp(int a, int b) {
	return a > b;
}
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int m;
		cin >> m;
		ll in1, in2;
		vector <dl> h(m);
		for (int i = 0; i < m; i++) {
			cin >> in1 >> in2;
			h[i] = {in2, in1};
		}
		sort(h.begin(), h.end());
		ll dp[m];
		dp[m - 1] = h[m - 1].second;
		for (int i = m - 2; i >= 0; i--) {
			dp[i] = max(dp[i + 1], h[i].second);
		}
		if (*max_element(arr, arr + n) > dp[0]) {
			cout << "-1\n";
			continue;
		}
		int j = 0;
		int cont = 1;
		ll mayor = 0;
		for (int i = 0; i < n; i++) {
			mayor = max(arr[i], mayor);
			int dist = i - j + 1;
			dl temp = {dist, 0};
			int x = lower_bound(h.begin(), h.end(), temp) - h.begin();
			if (x < m && mayor <= dp[x]) continue;
			cont++;
			mayor = 0;
			j = i;
			i--;
		}
		cout << cont << "\n";
	}
	return 0;
}