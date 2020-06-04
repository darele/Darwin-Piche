#include <bits/stdc++.h>
#define tam 100010

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vi> graph;

bool comp(int a, int b) {
	return a > b;
}

int n, x;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		string t;
		int cont = n >> 1;
		while (k > 1) {
			t += "()";
			cont--;
			k--;
		}
		for (int i = 0; i < cont; i++) t += "(";
		for (int i = 0; i < cont; i++) t += ")";
		vii ans;
		ans.reserve(n);
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) continue;
			for (int j = i + 1; j < n; j++) {
				if (s[j] == t[i]) {
					ans.push_back({i, j});
					reverse(s.begin() + i, s.begin() + j + 1);
					break;
				}
			}
		}
		cout << ans.size() << "\n";
		for (ii x : ans) {
			cout << x.first + 1 << " " << x.second + 1 << "\n";
		}
	}	
	return 0;
}
