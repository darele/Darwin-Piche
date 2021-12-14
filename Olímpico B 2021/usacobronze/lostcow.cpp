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

ifstream fin("lostcow.in");
ofstream fout("lostcow.out");

int main() {

    int x, y;
    fin >> x >> y;
    int i = 0;
    int ans = 0;
    while (1) {
        if ((i & 1) == 0) {
            if (y >= x && abs(x - y) <= (1 << i)) {
                ans += abs(x - y);
                break;
            }
        } else {
            if (x >= y && abs(x - y) <= (1 << i)) {
                ans += abs(x - y);
                break;
            }
        }
        ans += (1 << (i + 1));
        i++;
    }
    fout << ans << "\n";
    return 0;
}