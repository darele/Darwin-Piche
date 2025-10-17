#include <bits/stdc++.h>

using namespace std;

long long ans[35][35];

int main() {
	int h, w;
	cin >> h >> w;
	ans[h][w] = 1;
	for (int i = h; i >= 0; i--) {
		for (int j = w; j >= 0; j--) {
			if (j > 0) 
				ans[i][j - 1] += ans[i][j];
			if (i > 0)
				ans[i - 1][j] += ans[i][j];
		}
	}
	cout << ans[0][0] << endl;
	return 0;
}