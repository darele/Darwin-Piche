#include "combo.h"
#include <bits/stdc++.h>

using namespace std;

std::string guess_sequence(int N) {
  string ans = "";
  vector <char> v(4), v2;
  v2.reserve(3);
  v[0] = 'A';
  v[1] = 'B';
  v[2] = 'X';
  v[3] = 'Y';
  int coins = 0;
  int indice = 0;
  bool band = false;
  for (int j = 0; j < 3; j++) {
    int temp = press(ans + v[j]);
    if (temp > coins) {
      ans += v[j];
      coins = temp;
      indice = j;
      band = true;
      break;
    }
  }
  if (band == false) {
    coins++;
    ans += v[3];
    indice = 3;
  }
  for (int i = 0; i < 4; i++) {
    if (i == indice) continue;
    v2.push_back(v[i]);
  }
  for (int i = 1; i < N; i++){
    band = false;
    for (int j = 0; j < 2; j++) {
      int temp = press(ans + v2[j]);
      if (temp > coins) {
        ans += v2[j];
        coins = temp;
        band = true;
        break;
      }
    }
    if (band == false) {
      coins++;
      ans += v2[2];
    }
  }
  return ans;
}
