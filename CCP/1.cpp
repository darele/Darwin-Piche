#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <vii> graph;

bool comp(ll a, ll b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    string s;
    cin >> s;
    int n = s.size();
    int cont = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i + 1] == s[i - 1] && s[i] != s[i - 1]) cont++;
    }
    cout << cont << "\n";
	return 0;
}
