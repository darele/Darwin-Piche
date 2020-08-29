#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define inf 1000000005
 
using namespace std;
 
bool mat[1005][1005];
int arr[1005];
 
bool comp(int a, int b) {
    return (arr[a] == arr[b] ? a < b : arr[a] < arr[b]);
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) mat[i][j] = 1;
        }
    }
    vii ans;
    ans.reserve(n * n);
    for (int i = n - 1; i >= 0; i--) {
        vi c;
        c.reserve(n);
        for (int j = 0; j < i; j++) {
            if (mat[j][i]) {
                c.push_back(j);
            }
        }
        sort(c.begin(), c.end(), comp);
        for (int j : c) {
            ans.push_back({j, i});
        }
    }
    cout << ans.size() << "\n";
    for (ii x : ans) {
        cout << x.first + 1 << " " << x.second + 1 << "\n";
    }
	return 0;
}
