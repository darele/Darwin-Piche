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
    int a, b, s;
    cin >> a >> b >> s;
    int ans = abs(a) + abs(b);
    if (s < ans) {
        cout << "No\n";
    } else {
        s -= ans;
        if (s % 2) cout << "No\n";
        else cout << "Yes\n"; 
    }
    return 0;
}