/*
https://codeforces.com/problemset/problem/1409/E
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define tam 1000001

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, k;
    	cin >> n >> k;
    	map <int, int> kika;
    	vi x(n);
    	int in1, in2;
    	REP(0, n) {
    		cin >> x[i];
    	}
    	REP(0, n) {
    		cin >> in1;
    		kika[x[i]]++;
    	}
    	set <int> s(x.begin(), x.end());
    	x.assign(s.begin(), s.end());
    	n = x.size();
    	vi pre(n + 1, 0);
    	vi su(n + 1, 0);
    	int i = 0, j = 1;
    	int suma = kika[x[0]];
    	pre[0] = suma;
    	while (i < n) {
    		while (j < n && abs(x[j] - x[i]) <= k) {
    			suma += kika[x[j]];
    			pre[j] = max(suma, pre[j - 1]);
    			j++;
    		}
    		suma -= kika[x[i++]];
    	}
    	i = j = n - 1;
    	while (j >= 0) {
    		while (i >= 0 && abs(x[j] - x[i]) <= k) {
    			suma += kika[x[i]];
    			su[i] = max(suma, su[i + 1]);
    			i--;
    		}
    		suma -= kika[x[j--]];
    	}
    	int mayor = 0;
    	REP(0, n) {
    		mayor = max(mayor, pre[i] + su[i + 1]);
    	}
    	cout << mayor << "\n";
    }
    return 0;
}
