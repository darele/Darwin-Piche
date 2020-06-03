//lo hice solo
#include <bits/stdc++.h>
#define tam 100010

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vi> graph;

bool comp(int a, int b) {
	return a > b;
}

int n, x;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int in1, in2;
		int deg = 0;
		for (int i = 0; i < n - 1; i++) {
			cin >> in1 >> in2;
			if (in1 == x) deg++;
			if (in2 == x)deg++;
		}
		if (deg <= 1) {
			cout << "Ayush\n";
		} else {
			int temp = n - 1;
			if (temp % 2) {
				cout << "Ayush\n";
			} else {
				cout << "Ashish\n";
			}
		}
	}
	return 0;
}
