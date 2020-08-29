#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, ll>
#define vi vector <int>
#define graph vector <vi>
#define tam 300010
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	bool mat[n][m];
	ll u[n][m];
	ll d[n][m];
	ll r[n][m];
	ll l[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < m; i++) {u[0][i] = 0; l[i][0] = 0; r[i][m - 1] = 0; d[n - 1][i] = 0;}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (mat[i - 1][j]) u[i][j] = u[i - 1][j] + 1;
			if (mat[i][j - 1]) l[i][j] = l[i][j - 1] + 1;
		}
	}
	for (int i = n - 2; i >= 0; i++) {
		for (int j = m - 2; j >= 0; j++) {
			if (mat[i + 1][j]) d[i][j] = d[i + 1][j] + 1;
			if (mat[i][j + 1]) r[i][j] = r[i][j + 1] + 1;
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> in1 >> in2 >> in3;
		in2--, in3--;
		if (in1 == 1) {
			mat[in2][in3] = !mat[in2][in3];
			if (in2 + 1 < n) d[in2][in3] = d[in2 + 1][in3] + 1;
			if (in2 - 1 >= 0) {
				u[in2][in3] = u[in2 - 1][in3] + 1;
				d[in2 - 1][in3] = (mat[in2][in3] ? d[in2][in3] + 1 : 0);
			}
			if (in3 - 1 >= 0) l[in2][in3] = l[in2][in3 - 1] + 1;
			if (in3 + 1 < m) r[in2][in3] = r[in2][in3 + 1] + 1;
			for (int i = in2 - 2; i >= 0; i--) {
					if (mat[i + 1][in3]) d[i][in3] = d[i + 1][in3] + 1;
			}
		} else {

		}
	}
	return 0;
}
