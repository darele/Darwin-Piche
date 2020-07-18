#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <set <int> >
#define inf 1000000000
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vi dp(n + 1, inf);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int div = 1;
		while (div <= i) {
			int temp = (i / div) % 10;
			if (temp != 0) {
				dp[i] = min(dp[i], dp[i - temp] + 1);
			}
			div *= 10;
		}
	}
	cout << dp[n] << "\n";
	return 0;
}