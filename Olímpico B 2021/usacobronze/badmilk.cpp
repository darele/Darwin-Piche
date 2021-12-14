#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <int, int>
#define iii pair <int, ii>
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
#define tam 55

using namespace std;

ifstream fin("badmilk.in");
ofstream fout("badmilk.out");

int n, m, d, s;

int main() {

    fin >> n >> m >> d >> s;
    iii personas[d];
    int x;
    for (int i = 0; i < d; i++) {
        fin >> personas[i].ff;
        personas[i].ff--;
        fin >> personas[x].ss.ss >> personas[x].ss.ff;
    }
    sort(personas, personas + d);
    int a, b;
    int enfermos[n];
    for (int i = 0; i < n; i++) enfermos[i] = 0;
    for (int i = 0; i < s; i++) {
        fin >> a >> b;
        a--;
        enfermos[a] = b;
    }
    int j = 0;
    vector <bool> sospechosos(m + 5, 0);
    for (int i = 0; i < n; i++) {
        while (j < d && personas[j].ff == i) {
            if (personas[j].ss.ff < enfermos[i]) {
                sospechosos[personas[j].ss.ss] = 1;
            }
            j += 1;
        }
    }
    vector <bool> dosis(n + 5, 0);
    for (int i = 0; i < d; i++) {
        if (sospechosos[personas[i].ss.ss]) {
            dosis[personas[i].ff] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dosis[i]) ans++;
    }
    fout << ans << "\n";
    return 0;
}