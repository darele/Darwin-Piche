#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <set <int> >
#define inf 1000000000
 
using namespace std;

vi arr;

/*bool comp(int a, int b) {
	return arr[a] < arr[b];
}*/
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n;
		n = s.size();
		vi letras(256, 0);
		for (int i = 0; i < n; i++) {
			letras[s[i]]++;
		}
		cin >> n;
		arr.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int ac = 'z';
		int cont = 0;
		vi temp, temp2;
		temp.reserve(n);
		temp2.reserve(n);
		vector <bool> vis(n, 0);
		string ans;
		ans.assign(n, 'a');
		while (1) {
			int goal = 0;
			temp2.resize(0);
			cont = 0;
			for (int i = 0; i < n; i++) {
				if (vis[i]) continue;
				goal = 0;
				for (int x : temp) {
					goal += abs(x - i);
				}
				if (goal == arr[i]) {
					cont++;
					temp2.push_back(i);
				}
			}
			if (temp2.size() == 0) break;
			while (letras[ac] < cont) ac--;
			for (int x : temp2) {
				ans[x] = ac;
				vis[x] = 1;
				temp.push_back(x);
			}
			ac--;
		}
		cout << ans << endl;
	}
	return 0;
}