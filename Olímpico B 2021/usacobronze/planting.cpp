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

ifstream fin("planting.in");
ofstream fout("planting.out");

int main() {

    int n;
    fin >> n;
    int in1, in2;
    vi g(n + 5, 0);
    for (int i = 0; i < n - 1; i++) {
        fin >> in1 >> in2;
        g[in1]++;
        g[in2]++;
    }
    int mayor = *max_element(g.begin(), g.end());
    fout << mayor + 1 << "\n";
    return 0;
}