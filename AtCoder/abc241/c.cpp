#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
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

//La idea es para cada celda
//obtener la cantidad de cudrados negros
//hacia arriba, abajo, derecha e izquierda

void solve() {
    int n;
    cin >> n;
    string mat[n];
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    bool band = 0;
    int contnegro;
    int contblanco = 0;

    //Recorrer filas
    for (int i = 0; i < n; i++) {
        int contnegro = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '#') {
                contnegro++;
            } else {
                contblanco++;
                if (contblanco > 2) {
                    contnegro = 0;
                } else {
                    contnegro++;
                }
            }
            if (contnegro + min(2, contblanco) >= 6) {
                band = true;
            }
        }
    }
    //Funciona!! pero hacen falta las demas direcciones

    //Vertical
    for (int j = 0; j < n; j++) {
        int contnegro = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][j] == '#') {
                contnegro++;
            } else {
                if (contblanco > 2) {
                    contnegro = 0;
                } else {
                    contnegro++;
                }
            }
            if (contnegro + min(2, contblanco) >= 6) {
                band = true;
            }
        }
    }

    //Diagonales principales
    int contnegro = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int k = 0; i + k < n; k++) {
            if (mat[i + k][k] == '#') {
                contnegro++;
            } else {
                if (contblanco > 2) {
                    contnegro = 0;
                } else {
                    contnegro++;
                }
            }
            if (contnegro + min(2, contblanco) >= 6) {
                band = true;
            }
        }
    }
    for (int j = 1; j < n; j++) {
        for (int k = 0; j + k < n; k++) {
            if (mat[k][j + k] == '#') {
                contnegro++;
            } else {
                if (contblanco > 2) {
                    contnegro = 0;
                } else {
                    contnegro++;
                }
            }
            if (contnegro + min(2, contblanco) >= 6) {
                band = true;
            }
        }
    }

    //Diagonales secundarias
    for (int i = n - 1; i >= 0; i--) {
        for (int k = 0; n - 1 - k >= 0; k--) {
            if (mat[i + k][k] == '#') {
                contnegro++;
            } else {
                if (contblanco > 2) {
                    contnegro = 0;
                } else {
                    contnegro++;
                }
            }
            if (contnegro + min(2, contblanco) >= 6) {
                band = true;
            }
        }
    }

    cout << (band ? "Yes" : "No") << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        
        solve();
    }
    return 0;
}