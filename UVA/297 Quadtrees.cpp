/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=233
*/

#include <bits/stdc++.h>
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

bitset <1025> ans;

int e(int a) {
    int ans = 1;
    for (int i = 0; i < a; i++) {
        ans *= 4;
    }
    return ans;
}

void solve(string &s, int &ini, int in, int temp) {
    REP(0, 4) {
        if (s[ini] == 'p') {
            solve(s, ++ini, in + temp * i, temp / 4);
            continue;
        } else if (s[ini] == 'f') {
            REP2(in + temp * i, in + temp * i + temp) ans[j] = 1;
        }
        ++ini;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        ans.reset();
        int ini = 1;
        if (s1[0] == 'p') solve(s1, ini, 0, 1024 / 4);
        else {
            if (s1[0] == 'f') REP(0, 1024) ans[i] = 1;
        }
        ini = 1;
        if (s1[0] == 'p') solve(s2, ini, 0, 1024 / 4);
        else if (s2[0] == 'f') REP(0, 1024) ans[i] = 1;
        cout << "There are " << ans.count() << " black pixels." << "\n";
    }
    return 0;
}


