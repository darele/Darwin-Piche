/*
https://codeforces.com/contest/1371/problem/E1
*/

#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define mod 1000000007

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, pri;
    cin >> n >> pri;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    vi p(4005, n);
    for (int i = 0; i < arr[n - 1]; i++) p[i] = 0;
    int j = n - 1;
    for (int i = arr[n - 1] - 1; i >= 0; i--) {
        while (j >= 0 && arr[j] > i) j--;
        p[i] = j + 1;
    }
    vi ans;
    ans.reserve(n);
    for (int i = 1; i < arr[n - 1]; i++) {
        int x = i;
        bool band = true;
        for (int j = 0; j < n; j++) {
            int u = p[x];
            int temp = u - j;
            if (temp % pri == 0) {
                band = false;
                break;
            }
            x++;
        }
        if (band) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
	return 0;
}
