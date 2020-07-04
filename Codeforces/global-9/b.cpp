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

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ans[n][m];
		int mat[n][m];
		int c;
		int in;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c = 4;
				if (i == n - 1 || i == 0) c--;
				if (j == m - 1 || j == 0) c--;
				ans[i][j] = c;
			}
		}
		bool band = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> in;
				if (in > ans[i][j]) {
					band = false;
				}
			}
		}
		if (!band) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}