#include <iostream>
#include <fstream>
#include "grafo.h"
#include "caminos.h"
using namespace std;

bool resuelveCaso() {
    int v, a;
    cin >> v >> a;

    if (!std::cin) {
        return false;
    }

    Grafo g(v); //constructor grafo

    for (int i = 0; i < a; i++) {
        int a, b;
        cin >> a >> b;
        g.ponArista(a, b);
    } //grafo construido con todas las aristas 

    //calculamos el dfs del origen
    CaminosDFS camino(g, 0);

    int i = 0;
    bool libre = camino.aciclico() && camino.conexo();

    // escribir la solución

    if (libre) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
