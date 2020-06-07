#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <vi>
#define inf 1000000000
 
using namespace std;
 
bool comp(ll a, ll b) {
    return a > b;
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll x, y;
        x = min(a, b);
        y = max(a, b);
        int cont = 0;
        while (!(y & 1) && x != y) {
            y >>= 1;
            cont++;
        }
        if (x == y) {
            int ans = 0;
            ans += (cont / 3);
            cont -= (3 * (cont / 3));
            ans += (cont / 2);
            cont -= (2 * (cont / 2));
            ans += cont;
            cout << ans << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}