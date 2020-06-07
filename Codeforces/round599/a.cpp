#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <vi>
#define inf 1000000000

using namespace std;

bool comp(ll a, ll b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int ac, mayor = 0;
        for (int i = n - 1; i >= 0; i--) {
            ac = min(arr[i], n - i);
            mayor = max(ac, mayor);
        }
        cout << mayor << "\n";
    }
	return 0;
}
