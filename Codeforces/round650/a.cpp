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
    	string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; i += 2) {
            cout << s[i];
        }
        cout << s[n - 1];
        cout << "\n";
    }
    return 0;
}