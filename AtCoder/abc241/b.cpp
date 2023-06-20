#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
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

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map <int, int> b;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (b[x] > 0) {
            b[x]--;
        } else {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        
        solve();
    }
    return 0;
}