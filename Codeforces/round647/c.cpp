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
	ll arr[70];
	arr[0] = 1;
	for (ll i = 1; i < 70; i++) {
		arr[i] = arr[i - 1] * 2 + 1;
	}
	while (t--) {
		ll n;
		cin >> n;
		int i = 0;
		while (n >= (1ll << i)) i++;
		i--;
		ll ans = 0;
		while (i > -1) {
			if (n & (1ll << i)) {
				ans += arr[i];
			}
			i--;
		}
		cout << ans << "\n";
	}	
	return 0;
}