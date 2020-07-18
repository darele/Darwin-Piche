#include <bits/stdc++.h>
#define tam 100010
#define mod 1000000007
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define iii pair <ll, ii>

using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector <string> mat(n);
	vector <vl> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i].assign(n, 0);
		cin >> mat[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == '*') continue;
			if (j + 1 < n) {
				dp[i][j + 1] += dp[i][j];
				dp[i][j + 1] %= mod;
			}
			if (i + 1 < n) {
				dp[i + 1][j] += dp[i][j];
				dp[i + 1][j] %= mod;
			}
		}
	}
	if (mat[n - 1][n - 1] == '.') cout << dp[n - 1][n - 1] << "\n";
	else cout << "0\n";
	return 0;
}
