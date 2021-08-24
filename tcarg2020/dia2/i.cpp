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
#define i4 ii

using namespace std;

int n, m;
graph a;
map <int, i4> mapa;
//llave es indice en b
//i4.first es padre
//i4.second.second es primero o segundo

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a.resize(2);
    a[0].resize(n);
    a[1].resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
        //su indice es padre de el
        //bool = 1
        //k = 1
        mapa[i] = {i, 1};
    }
    int i1, i2, i3, i5;
    REP(0, m) {
        cin >> i1 >> i2;
        i2--;
        if (i1 == 1) {
            cin >> i3 >> i5;
            i3--;
            //borrar usando iteradores
            //i2 = x, i3 = y, i5 = k
            mapa[i3] = {i2, 0};
            auto it = mapa.find(i3);
            while (1) {
                auto it = mapa.upper_bound(i3);
                if (it == mapa.end()) break;
                if (it->first - i3 >= i5) break;
                mapa.erase(it);
            }
        } else {
            map<int, i4>::iterator it = mapa.upper_bound(i2);
            it--;
            int ab = it->second.second;
            int diff = i2 - it->first;
            int bc = it->second.first;
            cout << a[ab][bc + diff] << "\n";
        }
    }
    return 0;
}