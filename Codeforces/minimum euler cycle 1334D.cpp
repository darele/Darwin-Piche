/*
https://codeforces.com/problemset/problem/1334/D

el ciclo minimo de Euler es 1,2,1,3,...,1,n,2,3,2,4,...,2,n,3,4,...,n-2,n-1,n-2,n,n-1,n,1
Cuando estas emparejando uno, habran (n - 1) * 2 vertices en el recorrido, cuando emparejas 2 (n - 2) * 2
y como caso especial, el ultimo siempre es 1
solo averigua a que conjunto pertenece l, y simula el recorrido hasta r
*/

#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define F first
#define S second
#define tipo pair <ll, pair <ll, set <int> > >
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, l, r;
		cin >> n >> l >> r;
		if (l == (n * (n - 1)) + 1) {
			cout << 1 << "\n";
			continue;
		}
		ll i = 1;
		ll suma = 0;
		while (suma + ((n - i) << 1) < l) {
			suma += ((n - i) << 1);
			i++;
		}
		ll k = suma + 1;
		ll c;
		while (k <= r) {
			c = 0;
			while (c < ((n - i) << 1)) {
				if (k >= l && k <= r) {
					if (c & 1) {
						cout << i + 1 + (c >> 1) << " ";
					} else {
						cout << i << " ";
					}
				}
				c++;
				k++;
			}
			if (k == (n * (n - 1) + 1) && k == r) {
				cout << "1";
				break;
			}
			i++;
		}
		cout << "\n";
	}
	return 0;
}
