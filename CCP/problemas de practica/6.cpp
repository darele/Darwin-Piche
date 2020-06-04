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

bool comp(ll a, ll b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int h, w;
    cin >> h >> w;
    ll dp[2][w + 1];
    for (int i = 0; i < w + 1; i++) dp[0][i] = 1;
    for (int i = 1; i <= h; i++) {
        dp[i % 2][0] = 1;
        for (int j = 1; j < w + 1; j++) {
            dp[i % 2][j] = dp[i % 2][j - 1] + dp[(i + 1) % 2][j];
        }
    }
    cout << dp[h % 2][w] << "\n";
	return 0;
}
