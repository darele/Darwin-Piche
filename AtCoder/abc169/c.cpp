#include <bits/stdc++.h>
#define tam 100010
#define ull long long
 
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
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
	ull a;
	double b;
	cin >> a >> b;
	ull c = round(b * 100);
	ull ans = a * c;
	cout << (ans / 100) << "\n";
	return 0;
}