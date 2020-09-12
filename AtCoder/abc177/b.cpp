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
 
    string s, t;
    cin >> s >> t;
    int cont = 0;
    int mayor = 0;
    int n, m;
    n = s.size();
    m = t.size();
    REP(0, n - t.size() + 1) {
        cont = 0;
        REP2(i, i + t.size()) {
            if (s[j] == t[j - i]) cont++;
        }
        mayor = max(mayor, cont);
    }
    cout << m - mayor << "\n";
	return 0;
}
