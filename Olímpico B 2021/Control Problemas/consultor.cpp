#include <bits/stdc++.h>
#define TAM 1000000

using namespace std;

fstream f;

set <string> problemas;

void iniciar() {
  f.open("problemas.txt", ios::in);
  if (!f) cout << "ala\n";
  string algo;
  while (!f.eof()) {
    f >> algo;
    problemas.insert(algo);
  }
  f.close();
}

void finalizar() {
  f.open("problemas.txt", ios::out);
  for (auto i : problemas) {
    f << i << " ";
  }
  f.close();
}

bool consulta(string kika) {
  return problemas.find(kika) != problemas.end();
}

void insertar(string par) {
  string kika = par;
  int i = 0;
  while (i < kika.size()) {
    string val;
    for (; i < (int)kika.size() && kika[i] != ' '; i++) val += kika[i];
    problemas.insert(val);
    i++;
  }
}

void eliminar(string kika) {
  problemas.erase(kika);
}

int main() {
  iniciar();
  while (1) {
    cout << "Acciones\n\n1. Consultar un problema\n\n2. Agregar problemas\n\n3. Quitar un problema\n\n4. Salir\n\n";
    int accion;
    cin >> accion;
    string en;
    if (accion == 1) {
      string en;
      cin >> en;
      cout << (consulta(en) == 1 ? "\nYES\n\n" : "\nNO\n\n");
    }
    else if (accion == 2) {
      string en;
      getline(cin, en);
      getline(cin, en);
      insertar(en);
    }
    else if (accion == 3) {
      string en;
      cin >> en;
      eliminar(en);
    } else break;
  }
  finalizar();
  return 0;
}