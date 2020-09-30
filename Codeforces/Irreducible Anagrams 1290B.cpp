/*
https://codeforces.com/problemset/problem/1290/B
si el primero y ultimo son distintos
si hay al menos 3 letras
si la longitud del segmento es 1
*/

#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
#define graph vector <vi>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)

#define tam 200005

using namespace std;

int l[tam][30];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    REP(0, n) {
        REP2(0, 26) l[i + 1][j] = l[i][j];
        l[i + 1][s[i] - 'a']++;
    }
    int t;
    cin >> t;
    while (t--) {
        int in1, in2;
        cin >> in1 >> in2;
        if (s[in1 - 1] != s[in2 - 1]) cout << "Yes\n";
        else if (in1 == in2) cout << "Yes\n";
        else {
            int temp = 0;
            REP(0,26) {
                if (l[in2][i] - l[in1 - 1][i]) temp++;
            }
            if (temp > 2) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
