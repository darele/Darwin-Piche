#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
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
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        int temp = abs(a - b);
        cout << min(n - 1, temp + x) << "\n";
    }
    return 0;
}