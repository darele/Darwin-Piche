#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define mod 1000000007
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    ll arr[n];
    ll pre[n + 1] = {0};
    REP(0, n) {
        cin >> arr[i];
        pre[i + 1] = pre[i] + arr[i];
        pre[i + 1] %= mod;
    }
    ll suma = 0;
    REP(0, n) {
        suma += ((arr[i] * ((pre[n] + mod - pre[i + 1]) % mod)) % mod);
        suma %= mod;
    }
    cout << suma << "\n";
	return 0;
}
