#include <bits/stdc++.h>
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
#define tam 2005
#define mod (ll)1e09+7

using namespace std;

int n, l;
ll dp[2][tam];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l;
    for (int i = 0; i < tam; i++) {
        dp[(l - 1) % 2][i] = 1;
    }
    for (int i = l - 2; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; j * k <= n; k++) {
                dp[i % 2][j] += dp[(i + 1) % 2][j * k];
                dp[i % 2][j] %= mod;
            }
        }
        for (int j = 1; j <= n; j++) dp[(i + 1) % 2][j] = 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[0][i];
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}