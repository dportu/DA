
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
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



template <typename Valor>
class Dijkstra {
   public:
   Dijkstra(DigrafoValorado<Valor> const& g, int orig) : //inicializamos el vector de maximos a 0
   origen(orig),
   dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
      maxValues.assign(g.V(), 0);
      dist[origen] = 0;
      pq.push(origen, 0);
      while (!pq.empty()) {
         int v = pq.top().elem; pq.pop();
         for (auto a : g.ady(v))
         relajar(a);
      }
   }
   bool hayCamino(int v) const { return dist[v] != INF; }
   
   //new
   int maxValue(int v) {
      return maxValues[v];
   }

   Valor distancia(int v) const { return dist[v]; }
   private:
   
   //new 
   vector<int> maxValues;

   const Valor INF = std::numeric_limits<Valor>::max();
   int origen;
   std::vector<Valor> dist;
   std::vector<AristaDirigida<Valor>> ulti;
   IndexPQ<Valor> pq;
   void relajar(AristaDirigida<Valor> a) {
      int v = a.desde(), w = a.hasta();
      if (dist[w] > dist[v] + a.valor()) {
         dist[w] = dist[v] + a.valor(); ulti[w] = a;
         pq.update(w, dist[w]);

         // new
         if(a.valor() > maxValues[w] && a.valor() > maxValues[v]) {
            maxValues[w] = a.valor();
         }
         else if(maxValues[v] > maxValues[w]) {
            maxValues[w] = maxValues[v];
         }
      }
   }
};




// hay que usar caminos para poder calcular el valor maximo de las aristas dentro del camino creo
bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N, M;
   cin >> N >> M;
   
   if (!std::cin)  // fin de la entrada
      return false;
   // resolver el caso posiblemente llamando a otras funciones
   DigrafoValorado<int> g(N);
   for(int i = 0; i < M; i++) {
      int a, b, val;
      cin >> a >> b >> val;
      a--;
      b--;
      g.ponArista({a,b,val});
      g.ponArista({b,a,val});

   }
   //g.print();
   int origen, destino;
   cin >> origen >> destino;
   origen--;
   destino--;
   Dijkstra<int> dij(g, origen);
   // escribir la solución
   if(!dij.hayCamino(destino)) {
      cout << "IMPOSIBLE\n";
   }
   else {
      cout << dij.maxValue(destino) << "\n";
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
