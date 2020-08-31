#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
 
using namespace std;
 
vi p;
vi s;
 
int findset(int u) {return u == p[u] ? u : p[u] = findset(p[u]);}
 
void merge(int u, int v) {
    int x = findset(u), y = findset(v);
    if (x == y) return;
    if (s[x] > s[y]) {
        p[y] = x;
        s[x] += s[y];
    } else {
        p[x] = y;
        s[y] += s[x];
    }
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    p.resize(n + 5);
    s.assign(n + 5, 1);
    REP(0, n + 5) p[i] = i;
    int in1, in2;
    REP(0, m) {
        cin >> in1 >> in2;
        merge(in1, in2);
    }
    int mayor = 0;
    REP(0, n + 5) {
        mayor = max(s[findset(i)], mayor);
    }
    cout << mayor << "\n";
	return 0;
}
