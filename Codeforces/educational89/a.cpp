#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
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
    	ll x = min(a, b);
    	ll y = max(a, b);
    	ll ans = 0;
    	while (x > 0 && y > x) {
    		ll temp = min((y - x + 1) / 2, x);
    		y -= (2 * temp);
    		x -= temp;
    		ans += temp;
    	}
    	ll temp = (x / 3);
    	ans += (2 * temp);
    	x -= (3 * temp);
    	y -= (3 * temp);
    	ans += (x > 1);
    	cout << ans << "\n";
    }
    return 0;
}