
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "dijkstra.h"
#include "kruskal.h"
#include "digrafoValorado.h"
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
   vector<int> v(N);
   DigrafoValorado<int> g(N);
   
   for(int i = 0; i < N; i++) {
      int oro;
      cin >> oro;
      v[i] = oro;
   }

   for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      g.ponArista({a,b,0});
   }

   for(int i = 0; i < N; i++) {
      for(int j = i+1; j < N; j++) { // creamos aristas de valor oro hacia todos los demas vertices
         if(!g.hayArista(i,j)) { // solo cuando no sean amigos y por lo tanto ya haya una arista
            g.ponArista({i, j, v[i]});
         }
      }
   }
   // grafo completado
   vector<int> dijkstras(N);
   // yo q se tio lo q hay que hacer es dijkstra multiorigen sobre todos los vertices
   for(int i = 0; i < N; i++) {
      Dijkstra<int> dij(g, i);
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
