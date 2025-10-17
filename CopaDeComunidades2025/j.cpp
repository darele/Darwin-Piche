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
	int maximos[10] = {9, 1, 5, 5, 4, 5, 9, 7, 8, 9};
	int numero[105];
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		numero[i] = maximos[s[i] - '0'];
	}
	sort(numero, numero + n);
	reverse(numero, numero + n);
	for (int i = 0; i < n; i++) {
		cout << numero[i];
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