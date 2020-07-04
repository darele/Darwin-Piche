#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <set <int> >
#define inf 1000000000
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		int rep[n + 10];
		for (int i = 0; i < n + 10; i++) rep[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			rep[arr[i]]++;
		}
		int mex = 0;
		for (int i = 0; i < n + 10; i++) if (!rep[i]) {mex = i; break;}
		vi ans;
		ans.reserve(2 * n);
		int ac = 0;
		while (ac < n && arr[ac] == ac) ac++;
		while (1) {
			if (mex == n) {
				while (ac < n && arr[ac] == ac) ac++;
				if (ac >= n) {
					break;
				}
				rep[arr[ac]]--;
				arr[ac] = mex;
				rep[mex]++;
				ans.push_back(ac);
			} else {
				rep[arr[mex]]--;
				rep[mex]++;
				ans.push_back(mex);
				arr[mex] = mex;
			}
			for (int i = 0; i < n + 10; i++) if (!rep[i]) {mex = i; break;}
		}
		cout << ans.size() << "\n";
		for (int i : ans) {
			cout << i + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}