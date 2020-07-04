#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
#define graph vector <vi>
#define inf 1000000000
#define iii pair <int, ii>

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
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vi temp;
		temp.reserve(n);
		temp.push_back(arr[0]);
		int m;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i + 1] < arr[i]) {
				m = arr[i + 1];
				while (temp.size() > 1) {
					if (temp.back() < arr[i]) temp.pop_back();
					else break;
				}
				if (arr[i] < temp.back()) temp.push_back(m);
			}
		}
		int i = n - 1;
		while (temp.size() > 1) {
			if (temp.back() < arr[i]) temp.pop_back();
			else break;
		}
		if (arr[i] < temp.back()) temp.push_back(m);
		if (temp.size() <= 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}