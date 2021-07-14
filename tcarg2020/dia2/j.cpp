#include <bits/stdc++.h>
#define ll uint64_t
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

ll n, k;

ll gaus(ll x) {
    return (x * (x + 1)) / 2;
}

int ok(ll x) {
    ll temp = gaus(k) - gaus(x);
    if (temp > n) return -1;
    if (n - temp <= x) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    n--;
    k--;
    if (n == 0) {
        cout << "0\n";
        return 0;
    }
    if (n > gaus(k)) {
        cout << "-1\n";
    } else {
        ll ini, fin, mid;
        ini = 1, fin = k;
        mid = (ini + fin) / 2;
        while (fin > ini) {
            mid = (ini + fin) / 2;
            ll temp = ok(mid);
            if (temp == 1) {
                fin = mid - 1;
            } else if (temp == -1) {
                 ini = mid + 1;
            } else break;
        }
        if (ok(mid + 1) == 0) cout << (k - mid - 1) + 1 << "\n";
        else if (ok(mid) == 0) cout << (k - mid) + 1 << "\n";
        else cout << (k - mid + 1) + 1 << "\n";
    }
    return 0;
}