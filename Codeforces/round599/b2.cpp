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
		bool band = true;
		vi letras(256, 0);
		for (int i = 0; i < n; i++) {
			letras[s[i]]++;
			letras[t[i]]++;
		}
		for (int i = 'a'; i <= 'z'; i++) {
			if (letras[i] % 2) {
				band = false;
				break;
			}
		}
		if (band) {
			cout << "YES\n";
			vii ans;
			ans.reserve(2 * n);
			for (int i = 0; i < n; i++) {
				if (s[i] != t[i]) {
					int j;
					for (j = i + 1; j < n; j++) {
						if (t[j] == t[i]) {
							ans.push_back({i, j});
							swap(s[i], t[j]);
							break;
						}
					}
					if (j == n) {
						for (j = i + 1; j < n; j++) {
							if (s[j] == t[i]) {
								ans.push_back({j, j});
								ans.push_back({i, j});
								swap(s[j], t[j]);
								swap(s[i], t[j]);
								break;
							}
						}
					}
				}
			}
			cout << ans.size() << "\n";
			for (ii x : ans) {
				cout << x.first + 1 << " " << x.second + 1 << "\n";
			}
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
