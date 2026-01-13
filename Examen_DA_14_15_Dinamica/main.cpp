
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include "EnterosInf.h"
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
typedef struct {
   int potencia;
   int precio;
}tBombilla;

bool operator<(const tBombilla &a, const tBombilla &b) {
   return a.precio < b.precio;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N, pmin, pmax;
   cin >>N >> pmax >> pmin;
   if (!std::cin)  // fin de la entrada
      return false;
   // resolver el caso posiblemente llamando a otras funciones

   vector<tBombilla> v(N);
   for(int i = 0; i < N; i++) {
      int p;
      cin >> p;
      v[i].potencia = p;
   }
   for(int i = 0; i < N; i++) {
      int pr;
      cin >> pr;
      v[i].precio = pr;
   }

   Matriz<tBombilla> m(N+1,pmin+1, {0,INT_MAX});
   for(int i = 0; i < m.numfils(); i++) {
      m[i][0].precio = 0;
      m[i][0].potencia = 0;
   }
   for(int i = 1; i < m.numfils(); i++) {
      for(int j = 1; j < m.numcols(); j++) {

         if(v[i-1].potencia > pmax ) 
         {
            m[i][j] = m[i-1][j];
         }
         else {
            tBombilla up = m[i-1][j];
            tBombilla left;
            if(j-v[i-1].potencia >= 0) {
               if(m[i][j-v[i-1].potencia].precio == INT_MAX) {
               left.precio = INT_MAX;
               left.potencia = 0;
               }
               else {
                  left.precio = v[i-1].precio + m[i-1][j-v[i-1].potencia].precio;
                  left.potencia =v[i-1].potencia + m[i-1][j-v[i-1].potencia].potencia;
               }
            }
            else {
               left = v[i-1];
            }
            

            m[i][j] = min(up, left);
         }
      }
   }
   
   // escribir la solución
   if(m[N][pmin].precio != INT_MAX) {
      cout << m[N][pmin].precio << " " << m[N][pmin].potencia << "\n";
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
