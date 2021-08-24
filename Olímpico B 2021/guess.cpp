#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int in1, in2, in3;
    cout << "? 1 2" << endl;
    cin >> in1;
    cout << "? 2 3" << endl;
    cin >> in2;
    cout << "? 1 3" << endl;
    cin >> in3;
    v[2] = ((in1 + in2) - (in3)) / 2;
    v[1] = in1 - v[2];
    v[3] = in2 - v[2];
    for (int i = 4; i <= n; i++) {
        cout << "? 1 " << i << endl;
        cin >> in1;
        v[i] = in1 - v[1];
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    /*
    a, b, c
    a + b  +
    b + c
    ________
    a + 2b + c = x
    2b = x - a - c
    2b = x - (a + c)
    b = (x - (a + c)) / 2
    */
    return 0;
}