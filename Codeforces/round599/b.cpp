#include <bits/stdc++.h>
#define tam 100010

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> graph;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int n; 
		cin >> n;
		string s, t;
		cin >> s >> t;
		int cont = 0;
		bool band = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				if (cont) {
					band = false;
					break;
				}
				int j;
				for (j = i + 1; j < n ; j++) {
					if (t[j] != s[j] && t[j] == t[i]) {
						swap(s[i], t[j]);
						cont++;
						break;
					}
				}
				if (j == n) {
					band = false;
				}
			}
		}
		if (band) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
