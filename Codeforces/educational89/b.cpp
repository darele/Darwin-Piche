#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <dl>
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
		ll n, x, m;
		cin >> n >> x >> m;
		ll in1, in2;
		ll l, r;
		l = r = x;
		for (int i = 0; i < m; i++) {
			cin >> in1 >> in2;
			if ((in2 <= r && in2 >= l) || (in1 >= l && in1 <= r) || (l >= in1 && l <= in2) || (r <= in2 && r >= in1)) {
				l = min(in1, l);
				r = max(in2, r);
			}
		}
 		cout << r - l + 1 << "\n";
	}
	return 0;
}