#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
#define graph vector <vi>
#define mod 1000000007
#define iii pair <int, ii>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 	
	int n, x;
	cin >> n >> x;
	vl dp(x + 1, 0);
	ll arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 0; i < x; i++) {
		if (!dp[i]) continue;
		for (int j = 0; j < n; j++) {
			if ((arr[j] + i) <= x) {
				dp[arr[j] + i] += dp[i];
				dp[arr[j] + i] %= mod;
			}
		}
	}
	cout << dp[x] << "\n";
	return 0;
}