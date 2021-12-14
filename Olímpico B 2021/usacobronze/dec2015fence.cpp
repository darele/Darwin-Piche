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

ifstream fin("paint.in");
ofstream fout("paint.out");

int solve(int a, int b, int c, int d) {
    int ans = b - a;
    if (d > b) {
        ans += d - max(c, b);
    } else if (c < a) {
        ans += min(d, a) - c;
    }
    return ans;
}

int main() {
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    fout << solve(a, b, c, d) << "\n";
    return 0;
}