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

ifstream fin("pails.in");
ofstream fout("pails.out");

int main() {

    int x, y, m;
    fin >> x >> y >> m;
    int suma = 0;
    int mayor = 0;
    int total1;
    total1 = m / x;
    for (int i = 0; i <= total1; i++) {
        suma = i * x;
        suma += y * ((m - suma) / y);
        if (suma > mayor) {
            mayor = suma;
        }
    }
    fout << mayor << "\n";
    return 0;
}