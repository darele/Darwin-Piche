#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define inf 1000000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
	    int n, x;
	    cin >> n >> x;
	    int ac[n + 1];
	    ac[0] = 0;
	    int in;
	    for (int i = 0; i < n; i++) {
	        cin >> in;
	        ac[i + 1] = ac[i] + in;
	        ac[i + 1] %= x;
	    }
	    int j = inf;
	    int mayor = 0;
	    for (int i = 1; i <= n; i++) {
	        if (ac[i]) {
	            j = min(i, j);
	            mayor = max(mayor, i);
	        } else {
	            if (j != inf) mayor = max(mayor, i - j);
	        }
	    }
	    if (mayor) cout << mayor << "\n";
	    else cout << "-1\n";
	}
	return 0;
}
