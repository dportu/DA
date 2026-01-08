
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "dijkstra.h"
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

   int N, M;
   cin >> N >> M;
   
   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones

   DigrafoValorado<int> g(N);
   for(int i = 0; i < M; i++) {
      int a, b, value;
      cin >> a >> b >> value;
      a--;
      b--;
      g.ponArista({a,b,value});
      g.ponArista({b,a,value});
   }
   int indiana, tesoro;
   cin >> indiana >> tesoro;
   indiana--;
   tesoro--;
   Dijkstra<int> dij(g, indiana);
   
   // escribir la solución
   if(dij.hayCamino(tesoro)) {
      cout << dij.distancia(tesoro) << "\n";
   }
   else {
      cout << "IMPOSIBLE\n";
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
