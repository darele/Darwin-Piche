/*
ID: pc17011
TASK: stamps
LANG: C++14                 
*/
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

ifstream fin("stamps.in");
ofstream fout("stamps.out");

int main() {

    int n, k;
    fin >> k >> n;
    vl v(n);
    REP(0, n) fin >> v[i];
    vl dp[2];
    dp[0].assign(100005, k + 5);
    dp[1].assign(100005, k + 5);
    dp[0][0] = 0;
    REP(0, n) dp[0][v[i]] = 1;
    for (int i = 1; true; i++) {
        for (int j = 0; j < n; j++) {
            dp[i % 2][i % 10000] = 
                min(dp[i % 2][i % 10000],
                    dp[(i - 1) % 2][(i + 10000 - v[j]) % 10000] + 1);
        }
        if (dp[i % 2][i % 10000] > k) {
            cout << dp[i % 2][i % 10000] << "\n";
            fout << i - 1 << "\n";
            break;
        }
    }
    return 0;
}