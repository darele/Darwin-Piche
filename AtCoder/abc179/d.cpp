#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
#define ff first
#define ss second
#define graph vector <vector <int> >
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define mod 998244353
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    ii a[k];
    REP(0, k) {
    	cin >> a[i].ff >> a[i].ss;
    }
    vl dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = -1;
    ll suma = 0;
    REP(1, n) {
    	suma += dp[i];
    	suma = (suma + mod) % mod;
    	REP2(0, k) {
    		if (a[j].ff + i <= n) {
    			dp[a[j].ff + i] += suma;
    			dp[a[j].ff + i] %= mod;
    		}
    		if (a[j].ss + i + 1 <= n) {
    			dp[a[j].ss + i + 1] -= suma;
    			if (dp[a[j].ss + i + 1] >= 0) dp[a[j].ss + i + 1] %= mod;
    			else dp[a[j].ss + i + 1] = -((-1 * dp[a[j].ss + i + 1]) % mod);
    		}
    	}
    }
    suma += dp[n];
    suma = (suma + mod) % mod;
    cout << suma << "\n";
    return 0;
}
