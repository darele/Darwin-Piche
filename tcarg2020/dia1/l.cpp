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
#define tam 305

using namespace std;

int n;
int mat[tam][tam];
int dp1[tam][tam];
int dp2[tam][tam];

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp1[i][j] = mat[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            dp2[i][j] = mat[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }
    solve();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dp1[i][j] + dp2[i][j] - mat[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}