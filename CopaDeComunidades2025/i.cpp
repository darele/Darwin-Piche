#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define dl pair<ll, ll>
#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>
#define vll vector<dl>
#define graph vector<vi>
#define ff first
#define ss second
#define LIM 100005
#define inf 1000000000

using namespace std;

void solve() {
	int n;
	cin >> n;
	iii arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].ff >> arr[i].ss.ff >> arr[i].ss.ss;
	}
	sort(arr, arr + n);
	reverse(arr, arr + n);
	vector<int>dp(n, 0);
	for (int i = 0; i < n; i++) {
		dp[i] = max(1, dp[i]);
		int ant = i;
		for (int j = i + 1; j < n; j++) {
			iii u = arr[ant];
			iii v = arr[j];
			if (u.ff > v.ff && u.ss.ff > v.ss.ff && u.ss.ss > v.ss.ss) {
				dp[j] = max(dp[ant] + 1, dp[j]);
				ant = j;
			}
		}
	}
	int mayor = 0;
	for (int i = 0; i < n; i++) {
		mayor = max(dp[i], mayor);
	}
	cout << mayor << endl;
}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}