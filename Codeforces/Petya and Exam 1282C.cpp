/*
https://codeforces.com/problemset/problem/1282/C

la idea es hacer todos los problemas hasta un minuto antes del siguiente problema obligatorio
(en orden de tiempo de entrega)
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
#define tam 5005

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int m;
    cin >> m;
    while (m--) {
        ll n, t, a, b;
        cin >> n >> t >> a >> b;
        dl arr[n];
        int in;
        ll e, h;
        e = h = 0;
        REP(0, n) {
            cin >> in;
            if (in) h++;
            else e++;
            arr[i].ss = (in ? b : a);
        }
        REP(0, n) {
            cin >> in;
            arr[i].ff = in;
        }
        sort(arr, arr + n);
        ll suma = 0;
        ll mayor = 0;
        ll c = 0;
        REP(0, n) {
            if (suma <= arr[i].ff - 1) {
                //cout << i << " " << suma << " " << arr[i].ff << endl;
                ll temp = arr[i].ff - 1 - suma;
                ll easy = min(temp / a, e);
                temp -= (easy * a);
                ll hard = min(temp / b, h);
                mayor = max(mayor, easy + hard + c);
            }
            suma += arr[i].ss;
            if (arr[i].ss == a) e--;
            else h--;
            c++;
        }
        if (suma <= t) {
            ll temp = t - suma;
            ll easy = min(temp / a, e);
            temp -= (easy * a);
            ll hard = min(temp / b, h);
            mayor = max(mayor, easy + hard + c);
        }
        cout << mayor << "\n";
    }
    return 0;
}
