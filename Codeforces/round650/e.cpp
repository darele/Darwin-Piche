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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vi letras(26, 0);
		for (int i = 0; i < n; i++) {
			letras[s[i] - 'a']++;
		}
		sort(letras.begin(), letras.end(), comp);
		int i;
		vi copia(26);
		copia = letras;
		for (i = n; i > 0; i--) {
			int x = i % k;
			if (x == 0) x = k;
			if (k % x == 0) {
				letras = copia;
				int temp1 = i / x;
				int cont = 0;
				for (int j = 0; cont < x && j < 26; j++) {
					while (cont < x && letras[j] >= temp1) {letras[j] -= temp1; cont++;}
				}
				if (cont == x) break;
			}
		}
		cout << i << "\n";
	}
	return 0;
}
