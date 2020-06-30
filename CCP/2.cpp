#include <bits/stdc++.h>
#define tam 100005
#define inf 100000000
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <vi> graph;

bool comp(ll a, ll b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
    pair <int, int> mat[n * n + 5];
    int in;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> in;
            mat[in] = {i, j};
        }
    }
    int cont = 0;
    for (int i = 2; i <= (n * n); i++) {
        cont += (abs(mat[i].first - mat[i - 1].first) + abs(mat[i].second - mat[i - 1].second));
    }
    cout << cont << "\n";
	return 0;
}
