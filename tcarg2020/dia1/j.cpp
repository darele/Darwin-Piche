#include <bits/stdc++.h>
#define inf 1e09+5
#define vi vector <int>
#define ii pair <int, int>
#define vii vector <ii>

using namespace std;

int n, d, a, b;
map <int, vi> mapa;

int main() {
    cin >> n >> d >> a >> b;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        x *= a;
        y *= b;
        mapa[x+y].push_back(i);
    }
    vi ans;
    ans.reserve(n);
    for (auto i : mapa) {
        for (int j : i.second) {
            if (i.first <= d) {
                d -= i.first;
                ans.push_back(j + 1);
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}