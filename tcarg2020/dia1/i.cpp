#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int par = 0;
    int impar;
    for (int i = 0; i < n; i++) {
        cin >> impar;
        if (impar % 2 == 0) par++;
    }
    impar = n - par;
    if (impar % 2) cout << "YES\n";
    else {
        if (impar == 0) cout << "NO\n";
        else {
            if (par) cout << "YES\n";
            else cout << "NO\n";
        }
    } 
}

int main() {
    int t;
    cin >> t;
    while (t--)  {
        solve();
    }
    return 0;
}