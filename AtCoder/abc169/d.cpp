#include <bits/stdc++.h>
#define tam 10000010
 
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <set <int> > graph;
 
bool comp(int a, int b) {
	return a > b;
}
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
	ll n;
	ll copia;
	cin >> n;
	copia = n;
	if (n == 1) {
		cout << "0\n";
		return 0;
	}
	vl primos;
	if ((n & 1) == 0) {
		primos.push_back(2);
	}
	while ((n & 1) == 0) {
		n >>= 1;
	}
	for (ll i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			primos.push_back(i);
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		primos.push_back(n);
	}
	n = copia;
	ll in;
	ll cont = 0;
	for (int i = 0; i < (int)primos.size(); i++) {
		in = primos[i];
		while (n % in == 0) {
			n /= in;
			in *= primos[i];
			cont++;
		}
	}
	cout << cont << endl;
	return 0;
}