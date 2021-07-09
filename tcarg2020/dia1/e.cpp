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

int n;
vi arr;

void solve() {
    if (n == 1) {
        cout << "1 0\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i, j;
    i = 0, j = n - 1;
    int t = 0;
    int ans = 0;
    while (i < j) {
        if (arr[i] < arr[j]) {
            arr[j] -= arr[i];
            ans++;
            i++;
            if (i == j) break;
        } else if (arr[j] < arr[i]) {
            arr[i] -= arr[j];
            j--;
            if (j == i) {
                ans++;
                break;
            }
        } else {
            ans++;
            i++;
            j--;
        }
        if (i == j) {
            if (arr[i - 1] == arr[j + 1]) ans++;
            break;
        }
    }
    cout << ans << " " << n - ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    cin >> n;
    arr.resize(n);
    solve();
	return 0;
}