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

ifstream fin("billboard.in");
ofstream fout("billboard.out");

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    fin >> x3 >> y3 >> x4 >> y4;
    fin >> x1 >> y1 >> x2 >> y2;
    int ans = abs(x4 - x3) * abs(y4 - y3);
    int interseccionx = min(x4, x2) - max(x3, x1);
    int intersecciony = min(y4, y2) - max(y3, y1);
    if (interseccionx == (x4 - x3) ||
        intersecciony == (y4 - y3)) {
        ans -= interseccionx * intersecciony;
    }
    fout << ans << endl;
    return 0;
}