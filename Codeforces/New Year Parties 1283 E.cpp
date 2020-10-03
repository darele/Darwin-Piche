/*
https://codeforces.com/problemset/problem/1283/D
el mayor lo hacemos greedy, el menor es mas complejo
primero se unifican los elementos, luego si podes unir 3 en uno, hacelo
sino talves podrias hacer temp[i] + 1 == temp[i + 1] - 1, ahi solo puedo unir 2
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

    int n;
    cin >> n;
    int in;
    int arr[n];
    set <int> kika;
    REP(0, n) {
        cin >> in;
        kika.insert(in);
        arr[i] = in;
    }
    sort(arr, arr + n);
    int l = -1;
    int mayor = 0;
    vi temp(kika.begin(), kika.end());
    bool band = 0;
    int menor = temp.size();
    for (int i = 0; i < temp.size() - 1; i++) {
        if (temp[i] + 1 == temp[i + 1]) {
            menor--;
            if (i < temp.size() - 2 && temp[i + 1] + 1 == temp[i + 2]) {
                menor--;
                i += 2;
            } else i++;
        } else if (temp[i] + 1 == temp[i + 1] - 1) {
            i++;
            if (i < temp.size() - 2 && temp[i] + 1 == temp[i + 1] == temp[i + 2] - 1) {
                continue;
            }
            menor--;
        }
    }
    REP(0, n) {
        if (arr[i] - 1 > l) {
            mayor++;
            l = arr[i] - 1;
        } else if (arr[i] > l) {
            mayor++;
            l = arr[i];
        } else if (arr[i] + 1 > l) {
            mayor++;
            l = arr[i] + 1;
        }
    }
    cout << menor << " " << mayor << "\n";
    return 0;
}
