//lo hice solo
#include <bits/stdc++.h>
#define tam 100010

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
		string s;
		cin >> s;
		int n = s.size();
		int uno[n + 1];
		int cero[n + 1];
		uno[0] = cero[0] = 0;
		for (int i = 0; i < n; i++) {
			uno[i + 1] = uno[i] + (s[i] == '1' ? 1 : 0);
			cero[i + 1] = cero[i] + (s[i] == '0' ? 1 : 0);
		}
		int suma = 0;
		int menor = n;
		for (int i = 1; i <= n; i++) {
			suma = uno[i];
			suma += cero[n] - cero[i];
			menor = min(menor, suma);
			suma = cero[i];
			suma += uno[n] - uno[i];
			menor = min(menor, suma);
		}
		cout << menor << "\n";
	}
	return 0;
}
