// Coste en el tiempo
// Explicar que son las aristas y que son los vertices
// Explicar por qué usamos ese algoritmo y las modificaciones que le hagamos


/*@ <answer>
 *
 * Nombre y Apellidos: Nayra Betancor Cano y Daniel Portuondo Rodriguez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include "ARM_Kruskal.h"

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M; // Numero de arboles (vertices) Y numero de saltos posibles (aristas)
    cin >> N >> M;

    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado<int> grafo(N);
    int a, b, c;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        grafo.ponArista({ a - 1, b - 1, c });
    }

    // resolver el caso posiblemente llamando a otras funciones
    ARM_Kruskal<int> arm(grafo);

    // escribir la solución
    if (arm.ARM().size() == N - 1) {
        cout << arm.maximaLiana() << '\n';
    }
    else {
        cout << "Imposible\n";
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
