#include <bits/stdc++.h>
#define LIM 100005

using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int mayor = max(n1, n2);
	long long dp[mayor + 1];
	for (int i = 0; i <= mayor; i++) {
		dp[i] = mayor + 10;
	}
	dp[1] = 0;
	for (int i = 1; i < mayor; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				if (i + j <= mayor)
					dp[i + j] = min(dp[i + j], dp[i] + 1);
				if (i + i/j <= mayor)
					dp[i + i/j] = min(dp[i + i/j], dp[i] + 1);
			}
		}
	}
	cout << dp[n1] << " " << dp[n2] << endl;
	return 0;
}