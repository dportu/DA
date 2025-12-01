
/*@ <answer>
 *
 * Nombre y Apellidos: Daniel Portuondo Rodriguez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <climits>
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

int numero_de_caminos(const Matriz<int> &matrix, int i, int j, int &ret) {

   // Caso base
   if(i == 1 && j == 1) {
      return ret;
   }

   // Caso recursivo
   else {
      int up = matrix[i-1][j];
      int left = matrix[i][j-1];
      if(up == left) {
         ret++;
         numero_de_caminos(matrix, i-1, j, ret);
         numero_de_caminos(matrix, i, j-1, ret);
      }
      else{
         if(up < left) {
            return numero_de_caminos(matrix, i-1, j, ret);
         }
         else{
            return numero_de_caminos(matrix, i, j-1, ret);
         }
      }
   }

   return ret;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int n, m;
   cin >> n >> m;
   
   if (!std::cin) {  // fin de la entrada
      return false;
   }

   // Inicializamos la matriz a infinito
   Matriz<int> matrix(n+1, m+1, INT_MAX);
   matrix[1][1] = 0;
   
   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
         char a;
         cin >> a;
         if(a == 'X') {
            matrix[i][j] = INT_MAX;
         }
         else if(i != 1 || j != 1) { // si no estamos en matrix[1][1]
            int up = matrix[i-1][j];
            int left = matrix[i][j-1];
            int current = min(up, left);
            if(current < INT_MAX) {
               current++;
            }
            matrix[i][j] = current;// ( (i - 1) + (j - 1) );
         }
      }
   }
   
   if(matrix[n][m] == INT_MAX) {
      cout << "0\n";
      return true;
   }

   int ret = 1;
   numero_de_caminos(matrix, n, m, ret);
   cout << ret << "\n";

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
