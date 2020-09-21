/*
https://codeforces.com/contest/1329/problem/A

si la suma de los segmentos es menor que n, no se puede;

siempre el color i va a quedar al final para ahorrar espacio, al final si no logre cubrir todo
simplemente corre tantos segmentos a la izquierda como sea necesario
*/

#include <bits/stdc++.h>
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
#define tam 100005

using namespace std;

ll l[tam];

bool comp(int a, int b) {
    return l[a] > l[b];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    ll sum = 0;
    REP(0, m) {
        cin >> l[i];
        sum += l[i];
    }
    if (sum < n) {
        cout << "-1\n";
        return 0;
    }
    int ans[m];
    int menor = n;
    REP(0, m) {
        if (l[i] > n - i) {
            cout << "-1\n";
            return 0;
        }
        ans[i] = n - i - l[i];
        menor = min(ans[i], menor);
    }
    if (menor > 0) {
        ans[m - 1] = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (ans[i] + l[i] >= ans[i - 1]) break;
            else {
                ans[i - 1] = ans[i] + l[i];
            }
        }
    }
    REP(0, m) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}
