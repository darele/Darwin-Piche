#include <bits/stdc++.h>
#define tam 105

using namespace std;

typedef unsigned long long ll;
typedef pair <ll, ll> dll;

dll dp[tam][tam][tam];
bool vis[tam][tam][tam];
ll cont;

dll f(ll a, ll b, ll c) {
    if (min(a, min(b, c)) <= 3) {
        dp[a][b][c] = {a + 2*b + 3*c, !vis[a][b][c]};
        vis[a][b][c] = 1;
        return dp[a][b][c];
    } else if (a + b + c == 100) {
        dp[a][b][c] = {0, !vis[a][b][c]};
        vis[a][b][c] = 1;
        return dp[a][b][c];
    }
    if (vis[a][b][c]) {
        return dp[a][b][c] = {dp[a][b][c].first, 0};
    }
    vis[a][b][c] = 1;
    dll x = f(a - 1, b - 1, c - 1);
    dll y = f(a, b - 3, c -3);
    dll z = f(a / 2, b, c);
    dp[a][b][c].first = x.first + y.first + z.first;
    dp[a][b][c].second = 1 + x.second + y.second + z.second;
    return dp[a][b][c];
}

int main() {
    
    int a, b, c;
    cin >> a >> b >> c;
    cont = 0;
    dll ans = f(a, b, c);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}