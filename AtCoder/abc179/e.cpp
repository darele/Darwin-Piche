/*
En algun momento vas a tener que haber visitado
los m-1 posibles residuos, entonces se va a repetir un ciclo
por proiedades de modulo
solo calculalo y ya XD
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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll n, x, m;
    cin >> n >> x >> m;
   	vi residuo(m, 0);
    n--;
    residuo[x] = 1;
    ll suma = x;
    vl r;
    r.reserve(m);
    r.push_back(x);
    while (n) {
    	x *= x;
    	x %= m;
    	if (!x) {cout << suma << "\n"; return 0;}
    	if (residuo[x]) {
    		break;
    	}
    	suma += x;
    	r.push_back(x);
    	residuo[x] = 1;
    	n--;
    }
    reverse(r.begin(), r.end());
    while (r.back() != x) r.pop_back();
    ll seg = r.size();
    ll suma2 = 0;
    for (ll i : r) {
    	suma2 += i;
    }
    suma += ((n / seg) * suma2);
    reverse(r.begin(), r.end());
    n %= seg;
    REP(0, n) {
    	suma += r[i];
    }
    cout << suma << "\n";
    return 0;
}
