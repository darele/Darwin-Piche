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

ll mcd(ll a, ll b) {return b == 0 ? a : mcd(b, a % b);}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	ll n;
	cin >> n;
	ll m = n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			m = min(m, mcd(i, n / i));
		}
	}
	cout << m << "\n";
	return 0;
}
