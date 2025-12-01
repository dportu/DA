#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include "Matriz.h"
using namespace std;

int devolver_cambio(vector<int> const& M, int C) {
   int n = M.size();
   Matriz<int> targets(n+1, C+1, INT_MAX);
   targets[0][0] = 0;
   for (int i = 1; i <= n; ++i) {
      targets[i][0] = 0;
      for (int j = 1; j <= C; ++j) {
         if (M[i-1] > j)
            targets[i][j] = targets[i-1][j];
         else
            targets[i][j] = min(targets[i-1][j], targets[i][j - M[i-1]] + 1);
   
      }
   }

   bool base = false;
   vector<int> resul(M.size(), 0);
   int current = targets[C][C];
   int j = C;
   int x = C;
   int y = n;
   if(current == INT_MAX) {
     cout << "Imposible\n"; 
     base = true;
   }
   else {
      while(j > 0) {
         if(current > 0 && y > 1) { 
            if(M[y] > j) { // if m[i] > j -> nos vamos directamente al anterior
               resul[y]++;
               j -= M[y];
               x -= M[y];
            }
            else {
               if( (targets[x - M[y]] [y] + 1) < (targets[x][y-1]) ) { // comprobamos el menor 
                  resul[y]++;
                  j -= M[y];
                  x -= M[y];
               }
               else {
                  y--;
               }
            }
            
         }
         else {
            base = true;
         }
      }
   }

   cout << targets[C][C] << ": ";
   for(int i = 0; i < resul.size(); i++) {
      cout << resul[i] << " ";
   }
   cout << '\n';

   return targets[C][C];
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int valor, S;
   cin >> valor >> S;
   if (!std::cin)  // fin de la entrada
      return false;
   
   vector<int> puntuaciones;
   for(int i = 0; i < S; i++) {
      int v;
      cin >> v;
      puntuaciones.push_back(v);
   }
   // resolver el caso posiblemente llamando a otras funciones
   //diana(puntuaciones, valor, S);
   devolver_cambio(puntuaciones, valor);
   

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
/*


int diana(vector<int> const& M, int valor, int sector) {
   Matriz<int> targets(valor+1, sector+1, INT_MAX);
   targets[0][0] = 0;
   for (int i = 1; i <= valor; ++i) {
      targets[i][0] = 0;
      for (int j = 1; j <= sector; ++j) {
         if (M[i-1] > j) {
            targets[i][j] = targets[i-1][j];
         }
         else {
            targets[i][j] = min(targets[i][j - 1] + 1, targets[i - M[i-1]][j]);
         }
      }
   }
*/