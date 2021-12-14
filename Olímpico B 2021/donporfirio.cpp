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
#define mod 1000000007

using namespace std;

int n;
vi p, r;
vl s;
vector <pair <ll, ii> > aristas; 

void init(int n) {
    p.resize(n);
    r.assign(n, 0);
    s.assign(n, 1);
    for (int i = 0; i < n; i++) p[i] = i;
}

int findset(int u) {
    return u == p[u] ? u : p[u] = findset(p[u]);
}

ll merge(int u, int v, ll peso) {
    int x = findset(u);
    int y = findset(v);
    ll temp = (((peso * s[x]) % mod) * s[y]) % mod;
    if (r[x] >= r[y]) {
        p[y] = x;
        if (r[x] == r[y]) r[x]++;
        s[x] += s[y];
    } else {
        p[x] = y;
        s[y] += s[x];
    }
    return temp;
}

void solve() {
    cin >> n;
    aristas.resize(n - 1);
    init(n + 5);
    int x, y;
    ll b;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y >> b;
        aristas[i] = {b, {x, y}};
    }
    sort(aristas.begin(), aristas.end());
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += merge(aristas[i].ss.ff, aristas[i].ss.ss, aristas[i].ff);
        ans %= mod;
    }
    cout << ans << "\n";
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