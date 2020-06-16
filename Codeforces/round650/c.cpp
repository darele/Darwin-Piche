#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				int j;
				for (j = i + 1; j < n && j <= i + k; j++) {
					if (s[j] == '1') break;
				}
				if (j > i + k || j == n) {
					ans++;
				}
				i = j - 1;
			} else {
				i += k;
			}
		}
		cout << ans << "\n";
 	}
	return 0;
}