#include "decoder.h"
#include "decoderlib.h"
#include <algorithm>
#include <vector>
#include <iostream> // for debugging

using namespace std;

void decode(int N, int L, int X[])
{
    // Subtarea 1 y 2
    // sort(X, X + L);
    // for (int i = 0; i < N; i++) {
    //     output(X[i] % 256);
    // }

    // Subtarea 1, 2, 3 y 4
    // vector<int> ans(N, 0);
    // sort(X, X + L);
    // for (int i = 0; i < L; i++) {
    //     ans[X[i] / 8] |= (1 << (X[i] % 8));
    // }
    // for (int i : ans) {
    //     output(i);
    // }

    // Subtarea 5 (81 puntos)
//     vector<int> ans(N, 0);
//     for (int i = 0; i < L; i++) {
//         int pos = (X[i] & ((1 << 3) - 1));
//         ans[X[i] >> 3] |= (1 << pos);
//     }
//     for (int i : ans) {
//         output(i);
//     }
// }
