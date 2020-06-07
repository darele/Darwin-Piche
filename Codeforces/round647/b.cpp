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
		int n;
		cin >> n;
		vi arr(n);
		vector <bool> vis(4000, 0), vis2(4000, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			vis[arr[i]] = 1;
		}
		bool band = true;
		for (int i = 1; i < 1025; i++) {
			vis2.assign(4000, 0);
			band = true;
			for (int j = 0; j < n; j++) {
				int temp = arr[j] ^ i;
				if (vis[temp]) {
					if (vis2[temp]) {
						band = false;
						break;
					}
					vis2[temp] = 1;
				}
				else {
					band = false;
					break;
				}
			}
			if (band) {
				cout << i << "\n";
				break;
			}
		}
		if (band) continue;
		cout << "-1\n";
	}
	return 0;
}