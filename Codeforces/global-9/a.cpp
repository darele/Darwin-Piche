#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <int, int>
#define vii vector <ii>
#define graph vector <vi>
#define inf 1000000000
 
using namespace std;
 
bool comp(ll a, ll b) {
    return a > b;
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

   	int t;
   	cin >> t;
   	while (t--) {
   		int n;
   		cin >> n;
   		ll arr[n];
   		for (int i = 0; i < n; i++) {
   			cin >> arr[i];
   			if (i % 2) arr[i] = abs(arr[i]) * -1;
   			else arr[i] = abs(arr[i]);
   		}
   		for (int i = 0; i < n; i++) cout << arr[i] << " ";
   		cout << "\n";
   	}
    return 0;
}