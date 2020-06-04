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
		ll in1, in2;
		dl arr[n];
		dl arr2[n];
		for (int i = 0; i < n; i++) {
			cin >> in1 >> in2;
			arr[i] = {in2, in1};
			arr2[i] = {in1, in2};
		}
		sort(arr, arr + n);
		sort(arr2, arr2 + n);
		ll ans = max(arr2[n - 1].first - arr[0].first, 0ll);
		cout << ans << "\n";
	}
	return 0;
}
