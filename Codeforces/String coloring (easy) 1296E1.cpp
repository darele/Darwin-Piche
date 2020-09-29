/*
https://codeforces.com/contest/1296/problem/E1
todos los que estan en su lugar les pones 0, sino, lo buscas siempre hacia adelante, todos por los que pasaste les pones 0
hasta que encontres el que va en la posicion i, a ese le pones 1, lo inertas y si al final la cadena ordenada con la que 
estabas construyendo son iguales, yes, sino no
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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s, c;
    cin >> s;
    c = s;
    sort(c.begin(), c.end());
    string ans;
    int j = 0;
    for (int i = 0; i < n && j < n; i++) {
        if (c[i] == s[i]) {
            if (i >= j) {ans += "0"; j++;}
        } else {
            while (j < n && s[j] != c[i]) {
                ans += "0";
                j++;
            }
            if (j < n) {
                ans += "1";
                for (int k = j; k > i; k--) swap(s[k], s[k - 1]);
            }
            j++;
        }
    }
    bool band = 1;
    REP(0, n) if (s[i] != c[i]) band = 0;
    if (band) cout << "YES\n" << ans << "\n";
    else cout << "NO\n";
    return 0;
}
