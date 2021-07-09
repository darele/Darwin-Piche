#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <vii> graph;

ll n, m;
vl fac;

void iniciar() {
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= m;
    }
}

void solve() {
    ll ans = 0;
    ll temp;
    for (int i = 1; i <= n; i++) {
        temp = (n - i + 1);
        temp *= (fac[i]);
        temp %= m;
        temp *= fac[n - i + 1];
        temp %= m;
        ans += temp;
        ans %= m;
    }
    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    cin >> n >> m;
    iniciar();
    solve();
	return 0;
}
