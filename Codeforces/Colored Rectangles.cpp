/*
https://codeforces.com/contest/1398/problem/D
*/

#include <bits/stdc++.h>
#define ll uint64_t
#define ii pair <int, ll>
#define dl pair <ll, int>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vii>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)

using namespace std;

ll dp[205][205][205];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, o;
    cin >> n >> m >> o;
    ll a[n];
    ll b[m];
    ll c[o];
    REP(0, n) cin >> a[i];
    REP(0, m) cin >> b[i];
    REP(0, o) cin >> c[i];
    sort(a, a + n);
    sort(b, b + m);
    sort(c, c + o);
    ll mayor = 0;
    REP(0, n + 1) {
        REP2(0, m + 1) {
            for (int k = 0; k <= o; k++) {
                mayor = max(mayor, dp[i][j][k]);
                if (i + 1 <= n && j + 1 <= m)
                dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k],
                                    dp[i][j][k] + (a[n - 1 - i] * b[m - 1 - j]));
                if (i + 1 <= n && k + 1 <= o)
                dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1],
                                    dp[i][j][k] + (a[n - 1 - i] * c[o - 1 - k]));
                if (j + 1 <= m && k + 1 <= o)
                dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1],
                                dp[i][j][k] + (b[m - 1 - j] * c[o - 1 - k]));
            }
        }
    }
    cout << mayor << "\n";
    return 0;
}
