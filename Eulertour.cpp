#include <bits/stdc++.h>
#define ii pair <int, int>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>

using namespace std;

int n, m;
graph grafo;
vii aristas;
//Este arreglo me dice si puedo usar una cierta aristas
vector <bool> puedo;
//respuesta
vi ans;

void dfs(int u) {
    for (int i : grafo[u]) {
        //pregunto si puedo usar esa arista
        if (puedo[i] == 0) continue;
        //Extraemos v de una manera creativa
        int v = aristas[i].first + aristas[i].second - u;
        //desactivas la arista
        puedo[i] = 0;
        //solo cuando pude salir del nodo hacia algun otro es que lo agrego
        //a ans
        ans.push_back(u);
        dfs(v);
    }
//    ans.push_back(u);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //tenes n nodos y m aristas
    cin >> n >> m;
    grafo.assign(n + 5, vi());
    aristas.reserve(m);
    puedo.assign(m, 1);
    int in1, in2;
    for (int i = 0; i < m; i++) {
        cin >> in1 >> in2;
        aristas.push_back({in1, in2});
        //en lugar de meter el otro nodo metes el indice de la arista
        grafo[in1].push_back(i);
        grafo[in2].push_back(i);
    }
    //Suponiendo que haces la validacion
        //por aqui
    //Si se puede hacer un tour de Euler
    int s;
    //Le asignas el valor necesario a s
    //Cuando todos tienen degree par elegis cualquiera
    //sino elegis uno de los dos que lo tienen impar
    s = 4;
    dfs(s);
    //metes s otra vez para completar el ciclo
    //cuando todos son pares
        //ans.push_back(s);
    //Caso contrario metes el otro que tiene degree impar
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
