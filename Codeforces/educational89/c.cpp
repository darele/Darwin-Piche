#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
#define graph vector <vi>
#define inf 1000000000

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
		graph mat(n);
		for (int i = 0; i < n; i++) {
			mat[i].resize(m);
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}
		int total = (n + m - 1) >> 1;
		int ans = 0;
		vi uno(n + m, 0);
		vi cero(n + m, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) uno[i + j]++;
				else cero[i + j]++;
			}
		}
		int x = n + m - 2;
		for (int i = 0; i < total; i++) {
			ans += min(uno[i] + uno[x - i], cero[i] + cero[x - i]);
		}
		cout << ans << "\n";
 	}
	return 0;
}