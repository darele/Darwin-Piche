/*
https://codeforces.com/contest/1283/problem/D
ir tomando los que estan a mi derecha y a mi izquierda (comenzando por los arboles)
sacar la menor distancia (hacia el arbol de la derecha o al de la izquierda, de eso se encarga la priority queue
siempre y cuando aplique bien las operaciones con el set arr)
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

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    ll a[n];
    set <ll> kika, arr;
    REP(0, n) {
        cin >> a[i];
        kika.insert(a[i]);
        arr.insert(a[i]);
    }
    sort(a, a + n);
    priority_queue <dl, vector <dl>, greater <dl> > cola;
    REP(0, n) {
        if (kika.find(a[i] - 1) == kika.end()) {
            cola.push({1, a[i] - 1});
        }
        if (kika.find(a[i] + 1) == kika.end()) {
            cola.push({1, a[i] + 1});
        }
    }
    int cont = 0;
    vl ans;
    ans.reserve(m);
    ll sum = 0;
    while (cont < m) {
        dl u = cola.top();
        cola.pop();
        if (kika.find(u.second) != kika.end()) continue;
        cont++;
        ans.push_back(u.second);
        sum += u.first;
        if (kika.find(u.second - 1) == kika.end()) {
            auto temp = arr.upper_bound(u.second - 1);
            if (temp != arr.begin()) {
                temp--;
                cola.push({abs(*temp - (u.second - 1)), u.second - 1});
            }
            cola.push({u.first + 1, u.second - 1});
        }
        if (kika.find(u.second + 1) == kika.end()) {
            auto temp = arr.upper_bound(u.second + 1);
            if (temp != arr.end()) {
                cola.push({abs((u.second + 1) - *temp), u.second + 1});
            }
            cola.push({u.first + 1, u.second + 1});
        }
        kika.insert(u.second);
    }
    cout << sum << "\n";
    REP(0, m) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
