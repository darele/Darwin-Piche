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
 
	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		int cont = 0;
		while (cont < 200 && x < y) {
			cont++;
			if (x % 2 == 0) {
				x *= 3;
				x >>= 1;
			}
			else x--;
		}
		if (cont == 200) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
	return 0;
}