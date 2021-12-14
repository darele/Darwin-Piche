#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)

using namespace std;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    stack <int> mayor;
    mayor.push(-1);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= mayor.top()) {
            while (mayor.top() != -1 && arr[i] > mayor.top()) {
                mayor.pop();
            }
            cout << mayor.top() << " ";
            mayor.push(arr[i]);
        } else {
            cout << mayor.top() << " ";
            mayor.push(arr[i]);
        }
    }
    cout << "\n";
    while (mayor.top() != -1) mayor.pop();
    int ans[n];
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > mayor.top()) {
            while (mayor.top() != -1 && arr[i] > mayor.top()) {
                mayor.pop();
            }
            ans[i] = mayor.top();
            mayor.push(arr[i]);
        } else {
            ans[i] = mayor.top();
            mayor.push(arr[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        
        solve();
    }
    return 0;
}