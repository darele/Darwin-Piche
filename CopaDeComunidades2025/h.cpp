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

void solve() {
	int n;
	cin >> n;
	int ac[n + 1];
	ac[0] = 0;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ac[i + 1] = ac[i] + a;
	}
	int q;
	cin >> q;
	int l, r;
	cin >> l >> r;
	int ans = 0;
	for (int tam = 0; tam < r - l + 1; tam++)
		for (int i = l; i + tam <= r; i++) {
			if (ac[i + tam] - ac[i - 1] == tam + 1) {
				ans++;
			}
		}
	cout << ans << endl;
}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}