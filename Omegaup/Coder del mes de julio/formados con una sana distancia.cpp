#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int arr[n];
    vi ans(n, 0);
    int in;
    for (int i = 0; i < n - 1; i++) {
        cin >> in;
        arr[i] = in;
        ans[i] = 0;
    }
    int suma = 0;
    int c = 0;
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        while (suma && suma + arr[i] >= 150) {
            suma -= arr[j++];
            c--;
        }
        if (suma + arr[i] < 150) {
            suma += arr[i];
            c++;
        }
        ans[i + 1] += c;
    }
    suma = 0;
    c = 0;
    j = n - 2;
    for (int i = n - 2; i >= 0; i--) {
        while (suma && suma + arr[i] >= 150) {
            suma -= arr[j--];
            c--;
        }
        if (suma + arr[i] < 150) {
            suma += arr[i];
            c++;
        }
        ans[i] += c;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
	return 0;
}
