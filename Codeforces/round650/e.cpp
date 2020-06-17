/*
By progra123 ( https://www.youtube.com/channel/UCR-1vHM1j-MbRaE8Nab54gQ )
atcoder.jp
Problem: Decayed Bridges
section: abc 120
link to the problem 
https://omegaup.com/arena/CIIC-2016/
link to the video where I solve it:
*/
#include <bits/stdc++.h>
#define tam 100010
#define mod 1000000007
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define iii pair <ll, ii>

using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, l;
		cin >> n >> l;
		string s;
		cin >> s;
		vi letras(26, 0);
		for (int i = 0; i < n; i++) {
			letras[s[i] - 'a']++;
		}
		sort(letras.begin(), letras.end());
		int i;
		vi copia(26);
		vector <bool> vis;
		copia = letras;
		int ac = 0;
		for (i = n; i > 0; i--) {
			letras = copia;
			vis.assign(n, 0);
			bool band = true;
			for (int j = 0; !vis[j]; j++) {
				int temp = 0;
				for (int k = j; !vis[k % i]; k += l) {
					vis[k % i] = 1;
					temp++;
				}
				int k;
				for (k = 0; k < 26; k++) {
					if (letras[k] >= temp) {
						letras[k] -= temp;
						break;
					}
				}
				if (k == 26) {
					band = false;
					break;
				}
			}
			if (band) break;
		}
		cout << i << "\n";
	}
	return 0;
}
