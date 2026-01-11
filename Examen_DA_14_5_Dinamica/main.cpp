
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Matriz.h"
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

void resuelveCaso() {

   int k, s;
   cin >> k >> s;
   
   // leer los datos de la entrada
   Matriz<int>m(k+1,s+1,0);
   m[0][0] = 1; // ?
   for(int i = 1; i <= k; i++) {
      for(int j = 0; j <= s; j++) {
         if(i > j) {
            m[i][j] = m[i-1][j];
         }
         else {
            m[i][j] = m[i-1][j] + m[i][j-i];
         }
      }
   }

   cout << m[k][s] << "\n";

   // resolver el caso posiblemente llamando a otras funciones
   
   // escribir la solución
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
