// Coste en el tiempo
// Explicar que son las aristas y que son los vertices
// Explicar por qu� usamos ese algoritmo y las modificaciones que le hagamos


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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n
    if (arm.ARM().size() == N - 1) {
        cout << arm.maximaLiana() << '\n';
    }
    else {
        cout << "Imposible\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
