#include <bits/stdc++.h>

using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

int main() {
    int x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;
    fin >> x1 >> y1 >> x2 >> y2;
    fin >> x3 >> y3 >> x4 >> y4;
    fin >> x5 >> y5 >> x6 >> y6;
    int ans = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);
    int interseccionx = max(min(x6, x2) - max(x1, x5), 0);
    int intersecciony = max(min(y6, y2) - max(y5, y1), 0);
    ans -= interseccionx * intersecciony;
    interseccionx = max(min(x6, x4) - max(x1, x3), 0);
    intersecciony = max(min(y6, y4) - max(y5, y3), 0);
    ans -= interseccionx * intersecciony;
    fout << ans << endl;
    return 0;
}