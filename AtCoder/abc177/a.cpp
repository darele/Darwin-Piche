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
 
    double d, t, s;
    cin >> d >> t >> s;
    if (d / s < t || abs(d / s - t) < 0.0000001) cout << "Yes\n";
    else cout << "No\n";
	return 0;
}
