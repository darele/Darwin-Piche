#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main() {
	int n;
	cin >> n;
	long long  dp[7];
	dp[0] = 1;
	long long suma = 1;
	for (int i = 1; i <= 6; i++) {
		dp[i] = suma;
		suma += dp[i];
		suma %= mod;
	}
	for (int i = 7; i <= n; i++) {
		suma -= dp[i % 7];
		suma += mod;
		suma %= mod;
		dp[i % 7] = suma;
		suma += dp[i % 7];
		suma %= mod;
	}
	cout << dp[n % 7] << "\n";
}