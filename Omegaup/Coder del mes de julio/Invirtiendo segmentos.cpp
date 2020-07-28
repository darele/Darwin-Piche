#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define tam 10005

using namespace std;

vii q[tam];
int mat[tam][tam];
int j;

int f(int r, int &c) {
    for (j--; j >= 0; j--) {
        if (r >= q[c][j].first && r <= q[c][j].second) {
            int temp = r - q[c][j].first;
            return f(q[c][j].second - temp, c);
        }
    }
    return mat[r][c];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int cont = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = cont++;
        }
    }
    int in1, in2, in3;
    char op;
    for (int i = 0; i < m; i++) {
        cin >> op >> in1 >> in2;
        if (op == 'R') {
            cin >> in3;
            q[in1].push_back({in2, in3});
        } else {
            j = q[in2].size();
            cout << f(in1, in2) << "\n";
        }
    }
	return 0;
}
