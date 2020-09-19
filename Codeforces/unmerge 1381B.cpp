/*
https://codeforces.com/contest/1381/problem/B
*/

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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mayor = 0;
        int in = 0;
        int in1;
        cin >> mayor;
        vi kika;
        kika.reserve(2 * n);
        REP(1, n * 2) {
            cin >> in1;
            if (in1 > mayor) {
                kika.push_back(i - in);
                mayor = in1;
                in = i;
            }
        }
        kika.push_back(2 * n - in);
        int m = kika.size();
        vector <int> dp(n + 1, 0);
        dp[0] = 2;
         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[j] == 2 && j + kika[i] <= n) 
                dp[j + kika[i]] = max(1, dp[j + kika[i]]);
            }
            for (int j = 0; j <= n; j++) if (dp[j] == 1) dp[j] = 2;
        }
        if (dp[n]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
