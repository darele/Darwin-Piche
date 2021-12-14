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

ifstream fin("gymnastics.in");
ofstream fout("gymnastics.out");

int n, k;

int main() {

    fin >> k >> n;
    int mat[k][n];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            fin >> mat[i][j];
        }
    }
    ii actual;
    int cont = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            actual = {mat[0][i], mat[0][j]};
            bool consistente = true;
            for (int l = 1; l < k && consistente; l++) {
                bool primero = false;
                for (int m = 0; m < n && consistente; m++) {
                    if (actual.second == mat[l][m] && !primero) {
                        consistente = false;
                    }
                    if (mat[l][m] == actual.first) {
                        primero = true;
                    }
                }
            }
            if (consistente) {
                cont++;
            }
        }
    }
    fout << cont << "\n";
    return 0;
}