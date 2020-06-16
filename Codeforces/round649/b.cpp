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

	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    vi ans;
	    ans.reserve(n);
	    ans.push_back(arr[0]);
	    for (int i = 1; i < n - 1; i++) {
	        if (arr[i - 1] < arr[i] && arr[i + 1] > arr[i]) continue;
	        if (arr[i - 1] > arr[i] && arr[i] > arr[i + 1]) continue;
	        ans.push_back(arr[i]);
	    }
	    ans.push_back(arr[n - 1]);
	    cout << ans.size() << "\n";
	    for (int x : ans) {
	        cout << x << " ";
	    }
	    cout << "\n";
	}
	return 0;
}
