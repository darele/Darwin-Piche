/*
https://codeforces.com/contest/1371/problem/E2
*/

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

    int n, p;
    cin >> n >> p;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int ac = arr[0];
    map <int, int> last;
    for (int i = 0; i < n; i++) {
        if (ac == arr[i]) continue;
        last[ac] = i - 1;
        ac = arr[i];
    }
    last[ac] = n - 1;
    ii ans = {0, arr[n - 1]};
    for (int i = 0; i < n; i++) {
        auto x = last.lower_bound(arr[min(i + p - 1, n - 1)]);
        int mayor;
        if (x->second - i + 1 >= p) {
            mayor = x->first - i - 1;
        }
        else mayor = arr[n - 1];
        ans.first = max(ans.first, arr[i] - i);
        ans.second = min(ans.second, mayor);
    }
    cout << max(ans.second - ans.first + 1, 0) << "\n";
    for (int i = ans.first; i <= ans.second; i++) {
        cout << i << " ";
    }
    cout << "\n";
	return 0;
}
