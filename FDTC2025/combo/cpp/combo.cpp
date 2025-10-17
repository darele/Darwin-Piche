#include "combo.h"
#include <bits/stdc++.h>

using namespace std;

string guess_sequence(int N) {
    string s = "";
    string p = "";
    int coins, curCoins;
    curCoins = 0;
    p = "AB";
    coins = press(p);
    if (coins - curCoins >= 1) {
        if (coins - curCoins > 1) {
            s += "AB";
        } else {
            p = "A";
            coins = press(p);
            if (coins - curCoins == 1) {
                s += "A";
            } else {
                s += "B";
            }
        }
    } else {
        p = "X";
        coins = press(p);
        if (coins - curCoins == 1) {
            s += "X";
        } else {
            s += "Y";
        }
    }

    if (s.size() == N) return s;
    vector <string> valid;
    valid.reserve(3);
    if (s[0] != 'A') valid.push_back("A");
    if (s[0] != 'B') valid.push_back("B");
    if (s[0] != 'X') valid.push_back("X");
    if (s[0] != 'Y') valid.push_back("Y");
    while((int)s.size() < N - 1) {
        p = s + valid[0] + valid[0] + s + valid[0] + valid[1] + s + valid[0] + valid[2] + s + valid[1];
        coins = press(p);
        curCoins = s.size();
        if (coins - curCoins == 1) {
            s += valid[1];
        } else if (coins - curCoins == 2) {
            s += valid[0];
        } else {
            s += valid[2];
        }
    }

    p = s + valid[0];
    coins = press(p);
    curCoins = s.size();
    if (coins - curCoins == 1) {
        s += valid[0];
    } else {
        p = s + valid[1];
        coins = press(p);
        if (coins - curCoins == 1) {
            s += valid[1];
        } else {
            s += valid[2];
        }
    }

    cout << s << endl;
    return s;
}
