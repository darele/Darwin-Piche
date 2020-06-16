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
		int n;
		cin >> n;
		int arr[n];
		int par;
		par = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] % 2 == 0) par++;
		}
		if (par != (n + 1) / 2) {
			cout << "-1\n";
		} else {
			par = 0;
			for (int i = 0; i < n; i += 2) {
				if (arr[i] % 2 != i % 2) {
					par++;
				}
			}
			cout << par << "\n";
		}
	}
	return 0;
}