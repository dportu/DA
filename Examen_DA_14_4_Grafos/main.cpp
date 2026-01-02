
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "grafoValorado.h"
#include "kruskal.h"
using namespace std;


/*
    Planteamos un arbol de recubrimiento minimo, guardándonos a medida que lo hacemos el máximo valor entre las aristas del árbol.
    Este valor es el que debemos devolver.
    Si al finalizar de hacer el arbol no hemos recorrido todos los vértices, es inconexo y por lo tanto escribimos "IMPOSIBLE" por pantalla
*/

void resuelveCaso() {
   
    // leer los datos de la entrada
    int N, M;

    cin >> N >> M;
    GrafoValorado<int> g(M);
    for(int i = 0; i < M; i++) {
        int a, b, horas;
        cin >> a;
        cin >> b;
        cin >> horas;

        g.ponArista({a,b,horas});
    }

    ARM_Kruskal<int> kruskal(g);
    if(!kruskal.conexo()) {
        cout << "Imposible\n";
    }
    else {
        cout << kruskal.maxValue() << "\n";
    }
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
