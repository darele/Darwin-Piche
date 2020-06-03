//necesite el tutorial para hacerlo
#include <bits/stdc++.h>

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
	//ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <set <int> > c;
		int in1, in2;
		c.resize(k);
		for (int i = 0; i < k; i++) {
			cin >> in1;
			for (int j = 0; j < in1; j++) {
				cin >> in2;
				c[i].insert(in2);
			}
		}
		cout << "? " << n;
		for (int i = 1; i <= n; i++) {
			cout << " " << i;
		}
		cout << endl;
		int mayor, in, temp;
		cin >> mayor;
		int l = 1;
		int tam = n;
		int r = l + tam / 2 - 1;
		while (tam > 1) {
			cout << "? " << tam / 2;
			for (int i = l; i <= r; i++) {
				cout << " " << i;
			}
			cout << endl;
			cin >> temp;
			if (temp == mayor) {
				if (tam < 4) in = l;
				tam /= 2;
			} else {
				if (tam == 2) in = l + 1;
				l = r + 1;
				tam -= (tam / 2);
			}
			r = l + tam / 2 - 1;
		}
		vi ans(k);
		for (int i = 0; i < k; i++) {
			if (c[i].find(in) == c[i].end()) ans[i] = mayor;
			else {
				cout << "? " << n - c[i].size();
				for (int j = 1; j <= n; j++) {
					if (c[i].find(j) != c[i].end()) continue;
					cout << " " << j;
				}
				cout << endl;
				cin >> ans[i];
			}
		}
		cout << "! ";
		for (int x : ans) {
			cout << x << " ";
		}
		cout << endl;
		string s;
		cin >> s;
		if (s == "Incorrect") break;
	}
	return 0;
}
