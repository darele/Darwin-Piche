#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)

using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;
    ll m = 0;
    string s;
    REP(0, n) {
        cin >> s;
        if (s == "halfplus") {
            m |= (1ll << i);
        }
    }
    ll suma = 0;
    while (m > 0) {
        suma += p * (m >> 1);
        if (m & 1) {
            suma += p / 2;
        }
        m >>= 1;
    }
    cout << suma << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        
        solve();
    }
    return 0;
}