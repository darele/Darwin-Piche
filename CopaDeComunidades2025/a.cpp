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
	int arr[4];
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 4);
	cout << abs(arr[3] + arr[0] - arr[1] - arr[2]) << endl;
}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}