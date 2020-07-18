#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <dl>
#define graph vector <vi>
#define inf 100000000
 
using namespace std;
 
bool comp(int a, int b) {
	return a > b;
}
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, x;
	cin >> n >> x;
	int arr[n];
	int dp[x + 1];
	for (int i = 0; i <= x; i++) dp[i] = x + 10;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j] <= i) {
				dp[i] = min(dp[i - arr[j]] + 1, dp[i]);
			}
		}
	}
	if (dp[x] < x + 10) cout << dp[x] << "\n";
	else cout << "-1\n";
	return 0;
}