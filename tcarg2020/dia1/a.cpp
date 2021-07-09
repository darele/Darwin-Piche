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

void solve() {
    ll a, b;
    cin >> a >> b;
    if (b > a) {
        cout << (1 + (abs(b - a) % 2 == 0)) << "\n";
    } else if (b < a) {
        cout << (1 + (abs(b - a) % 2)) << "\n";
    }else {
        cout << "0\n";
    }
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}