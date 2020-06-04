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
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vi ans(n);
		vector <bool> usado(n + 1, 0);
		int j = 1;
		bool band = true;
		ans[0] = arr[0];
		usado[arr[0]] = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i] > arr[i - 1]) {
				ans[i] = arr[i];
				usado[arr[i]] = 1;
			} else {
				while (j < n && usado[j]) j++;
				if (j > arr[i]) {
					band = false;
					break;
				}
				ans[i] = j;
				usado[j] = 1;
			}
		}
		if (!band) {
			cout << "-1\n";
			continue;
		}
		for (int x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
