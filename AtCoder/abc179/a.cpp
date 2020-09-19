#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define F first
#define S second
#define tipo pair <ll, pair <ll, set <int> > >
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;
	cout << s;
	if (s.back() == 's') {
		cout << "es";
	} else {
		cout << "s";
	}
	cout << "\n";
	return 0;
}