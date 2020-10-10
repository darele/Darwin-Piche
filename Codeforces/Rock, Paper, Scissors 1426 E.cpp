/*
https://codeforces.com/contest/1426/problem/E
para el maximo es un poco obvio
para el minimo tenemos que tomar las opciones que dirigen a un empate y
las que llevan a una perdida, y tomar todas las permutaciones de hacer todos esos matches
y obtener el minimo
*/

#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
#define graph vector <vi>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a, j < b; j++)
#define REPS(a, b, c) for (int i = a, i < b; i += c)

#define inf 1000000000

using namespace std;

ii pares[6] = {{0, 0}, {1, 1}, {2, 2}, {0, 2}, {1, 0}, {2, 1}};
bitset <10> vis;
int ac, menor;
int a[3], b[3];
int n;

void solve(int i) {
	if (i == 6) {
		menor = min(menor, n - ac);
	}
	int temp;
	for (int i = 0; i < 6; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		temp = min(a[pares[i].first], b[pares[i].second]);
		ac += temp;
		a[pares[i].first] -= temp;
		b[pares[i].second] -= temp;
		solve(i + 1);
		ac -= temp;
		a[pares[i].first] += temp;
		b[pares[i].second] += temp;
		vis[i] = 0;
	}
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    int mayor = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    menor = n;
    ac = 0;
    solve(0);
    cout << menor << " " << mayor << "\n";
    return 0;
}
