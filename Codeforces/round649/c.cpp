#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vi arr(n);
	int ac = -1;
	vi u;
	u.reserve(n + 1);
	for (int i = 0; i < n; i++) {
	    cin >> arr[i];
	    if (arr[i] != ac) {
	        ac = arr[i];
	        u.push_back(arr[i]);
	    }
	}
	u.push_back(1000000);
	int j = 0;
	ac = 0;
	vi ans;
	ans.reserve(n);
	for (int i = 0; i < n; i++) {
	    if (i > 0 && arr[i] != arr[i - 1]) {
	        ans.push_back(arr[i - 1]);
	    } else {
	        while (u[j] == ac) {ac = u[j] + 1; j++;}
	        ans.push_back(ac++);
	    }
	}
	for (int x : ans) {
	    cout << x << " ";
	}
	cout << "\n";
	return 0;
}
