#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <vector <int> >
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define inf 1000000000
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    ll n, m, p;
    cin >> n >> m;
    cin >> p;
    ll in;
    REP(0, p) {
    	cin >> in;
    	ll fila = n - 1 - (in - 1) % n;
    	ll columna = (in - 1) / n;
    	cout << (m * fila) + columna + 1 << " ";
    }
    cout << "\n";
    return 0;
}