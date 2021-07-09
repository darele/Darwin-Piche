#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define tam 1005

using namespace std;

ll dp[tam][tam];

ll ncr(int n, int k) {
    if (k > n) return 0;
    if (n == k) return 1;
    if (k == 0) return 1;
    if (dp[n][k]) return dp[n][k];
    return dp[n][k] = (ncr(n-1,k-1) + ncr(n-1,k)) % mod;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << (ncr(n-1, 2*k) * ncr(m-1,2*k)) % mod << "\n";
    return 0;
}