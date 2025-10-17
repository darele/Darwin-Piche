#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define dl pair<ll, ll>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<dl>
#define graph vector<vi>
#define LIM 100005

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	if (k > n) return;
	map<int, int> ventana;
	int i;
	int arr[n];
	for (i = 0; i < n && i < k; i++) {
		cin >> arr[i];
		ventana[arr[i]]++;
	}
	vector<int> ans;
	ans.reserve(n - k + 5);
	ans.push_back(ventana.rbegin()->first);
	for (; i < n; i++) {
		cin >> arr[i];
		ventana[arr[i - k]]--;
		ventana[arr[i]]++;
		if (ventana[arr[i - k]] == 0) {
			ventana.erase(arr[i - k]);
		}
		ans.push_back(ventana.rbegin()->first);
	}
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++) {
		cout << " " << ans[i];
	}
	cout << endl;
}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}