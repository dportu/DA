
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "grafoValorado.h"
#include "kruskal.h"
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

   GrafoValorado<int> g(N);
   for(int i = 0; i < M; i++) {
      int a, b, value;
      cin >> a >> b >> value;
      a--;
      b--;
      g.ponArista({a,b,value});
   }

   ARM_Kruskal kru(g);

   if(kru.conexo()) {
      cout << kru.costeARM() << "\n";
   }
   else {
      cout << "Imposible\n";
   }
   
   // escribir la solución

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
