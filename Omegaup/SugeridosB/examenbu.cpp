#include <bits/stdc++.h>
#define tam 20
#define inf 1000000005

using namespace std;
typedef pair <int, int> ii;

int n;
ii arr[tam];
int dp[2][185];

int main() {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 180; j++) {
            if (arr[i].first <= j) {
                dp[i%2][j] = max(dp[(i+1)%2][j], arr[i].second + dp[(i+1)%2][j - arr[i].first]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 180; i++) {
        ans = max(dp[(n-1)%2][i], ans);
    }
    cout << ans << "\n";
    return 0;
}