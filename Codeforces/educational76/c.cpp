#include <bits/stdc++.h>
#define tam 100010
 
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vi> graph;
 
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
		vector <vi> num(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			num[arr[i]].push_back(i);
		}
		int menor = n + 1;
		for (int i = 1; i <= n; i++) {
			if (num[i].size() <= 1) continue;
			for (int j = 1; j < num[i].size(); j++) {
				menor = min(menor, num[i][j] - num[i][j - 1] + 1);
			}
		}
		if (menor < n + 1) cout << menor << "\n";
		else cout << "-1\n";
	}
	return 0;
}