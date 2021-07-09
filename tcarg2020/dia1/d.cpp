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

int a, b, n;

void solve() {
    int x;
    int c = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            if (a) a--;
            else {
                if (b) {
                    b--;
                    c++;
                }
                else {
                    if (c) c--;
                    else ans++; 
                }
            }
        } else {
            if (b) b--;
            else ans += 2;
        }
    }
    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    cin >> n >> a >> b;
    solve();
	return 0;
}