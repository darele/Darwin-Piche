//lo hice solo
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

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int odd = 0, even;
		int in;
		for (int i = 0; i < n; i++) {
			cin >> in;
			if (in % 2) odd++;
		}
		even = n - odd;
		int temp = min(even, k);
		k -= temp;
		if (k & 1) {
			cout << "YES\n";
		} else {
			if (even > 0 && odd > k) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
