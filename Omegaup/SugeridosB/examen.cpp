#include <bits/stdc++.h>
#define tam 20
#define inf 1000000005

using namespace std;
typedef pair <int, int> ii;

int n;
ii arr[tam];
int dp[60*3 + 5][tam];

int solve(int t, int i) {
    if (i > n) return -inf;
    if (t < 0) return -inf;
    if (i == n) return 0;
    if (dp[t][i] != -1) return dp[t][i];
    int ans = max(solve(t, i + 1), arr[i].second + solve(t - arr[i].first, i + 1));
    dp[t][i] = ans;
    return ans;
}

int main() {
    
    cin >> n;
    for (int i = 0; i < 60*3 + 5; i++) {
        for (int j = 0; j < tam; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << solve(60 * 3, 0) << "\n";
    return 0;
}