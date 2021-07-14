#include <bits/stdc++.h>
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    bool band = 1;
    for (int i = 0; i < ((int)s.size() - p); i++) {
        if (s[i] == '.') {
            if (s[i + p] == '.') {
                s[i] = '0';
                s[i + p] = '1';
            } else {
                if (s[i + p] == '1') {
                    s[i] = '0';
                } else {
                    s[i] = '1';
                }
            }
            band = false;
            break;
        }
        else if (s[i] != s[i + p]) {
            if (s[i + p] == '.') {
                if (s[i] == '1') s[i + p] = '0';
                else s[i + p] = '1';
            }
            band = 0;
            break;
        }
    }
    if (band) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0 ; i < n; i++) {
        if (s[i] == '.') cout << 0;
        else cout << s[i];
    }
    return 0;
}