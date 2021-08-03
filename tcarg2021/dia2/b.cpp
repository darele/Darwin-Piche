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

vi p, r;
vl s;

void ini(int n) {
    p.resize(n);
    REP(0, n) p[i] = i;
    r.assign(n, 0);
    s.assign(n, 1);
}

int f(int u) {return u == p[u] ? u : p[u] = f(p[u]);}

bool sameset(int u, int v) {return f(u) == f(v);}

void merge(int u, int v) {
    int x, y;
    x = f(u);
    y = f(v);
    if (x == y) return;
    if (r[x] >= r[y]) {
        if (r[x] == r[y]) r[x]++;
        p[y] = x;
        s[x] += s[y];
    } else {
        p[x] = y;
        s[y] += s[x];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    ini(n + 5);
    int in1, in2;
    REP(0, m) {
        cin >> in1 >> in2;
        merge(in1, in2);
    }
    ll peligro = (1ll << (s[f(1)] - 1));
    REP(2, n + 1) {
        if (!sameset(i, 1)) {
            peligro *= (1ll << (s[f(i)] - 1));
            merge(i, 1);
        }
    }
    cout << peligro << "\n";
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