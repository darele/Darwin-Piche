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

int n;

int makeQuery(vi &v1, vi &v2) {
    int ans;
    cout << v1.size() << " " << v2.size();
    for (int i : v1) {
        cout << " " << i;
    }
    for (int i : v2) {
        cout << " " << i;
    }
    cout << endl;
    cin >> ans;
    if (ans == -1) {
        exit(0);
    }
    return ans;
}

void solve() {
    cin >> n;

    //Obtener distancia mas lejano al nodo 1
    vi v1 = {1};
    vi v2;
    v2.reserve(n - 1);
    for (int i = 1; i <= n; i++) {
        if (v1[0] == i) continue;
        v2.push_back(i);
    }
    int ans = makeQuery(v1, v2);
    
    //Averiguar cual de los nodos 2 al n es el mas lejano usando búsqueda binaria
    int ini = 2;
    int fin = n + 1;
    int mid = (ini + fin) / 2;
    while (fin - ini > 1) {
        mid = (ini + fin) / 2;
        v2.clear();
        for (int i = ini; i < mid; i++) {
            v2.push_back(i);
        }
        int result = makeQuery(v1, v2);
        if (result < ans) {
            ini = mid;
        } else {
            fin = mid;
        }
    }
    mid = (ini + fin) / 2;
    // if (mid + 1 <= n) {
    //     mid += 1;
    //     v2.clear();
    //     v2.push_back(mid + 1);
    //     if (makeQuery(v1, v2) < ans) {
    //         mid -= 1;
    //         v2.clear();
    //         v2.push_back(mid);
    //         if (makeQuery(v1, v2) < ans) {
    //             mid -= 1;
    //         }
    //     }
    // }
    

    //Hallada la hoja mas lejana, preguntar desde esa hoja a todas las demas
    v1[0] = mid;
    v2.clear();
    for (int i = 1; i <= n; i++) {
        if (v1[0] == i) continue;
        v2.push_back(i);
    }
    ans = makeQuery(v1, v2);
    cout << "-1 " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        
        solve();
    }
    return 0;
}