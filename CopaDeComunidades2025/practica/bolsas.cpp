#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b;
	int ans;
	ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ans += a * b;
	}
	cout << ans << endl;
	return 0;
}