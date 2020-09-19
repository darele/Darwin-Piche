#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define tam 1000001

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int cont = 0;
    bool band = 0;
    int in1, in2;
    REP(0, n) {
    	cin >> in1 >> in2;
  		if (in1 == in2) cont++;
  		else {
  			if (cont >= 3) band = true;
  			cont = 0;
  		}
    }
    if (cont >= 3) band = true;
    cout << (band ? "Yes" : "No") << "\n";
    return 0;
}
