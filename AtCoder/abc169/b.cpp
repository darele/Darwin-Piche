#include <bits/stdc++.h>
#define mod 1000000000000000000
 
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
 
	int n;
	cin >> n;
	ll p = 1;
	ll arr[n];
	ll in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		arr[i] = in;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (p == 0) break;
		if (arr[i] > (mod / p)) {
			cout << -1 << "\n";
			return 0;
		}
		p *= arr[i];
	}
	cout << p << "\n";
	return 0;
}