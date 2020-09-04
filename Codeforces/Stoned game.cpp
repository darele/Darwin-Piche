/*
https://codeforces.com/contest/1396/problem/B
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
        int suma = 0;
        int mayor = 0;
        int in;
        REP(0, n) {
            cin >> in;
            suma += in;
            mayor = max(in, mayor);
        }
        if (mayor > suma / 2 || suma % 2) cout << "T\n";
        else cout << "HL\n";
    }
    return 0;
}
