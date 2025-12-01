#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include "Matriz.h"
using namespace std;

vector<int> dardos_min(vector<int> const& M, int C) {
    int n = M.size();
    Matriz<int> dardos(n+1, C+1, INT_MAX);
    dardos[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dardos[i][0] = 0;
        for (int j = 1; j <= C; ++j) {
            if (M[i-1] > j) {
                dardos[i][j] = dardos[i-1][j];
            }
            else {
                int a = dardos[i-1][j];
                int b = dardos[i][j - M[i-1]];

                if(b != INT_MAX) {
                    b++;
                }
                dardos[i][j] = min(a, b);
            }
        }
    }

    vector<int> sol;
    if (dardos[n][C] != INT_MAX) {
        int i = n, j = C;
        while (j > 0) { // no hemos llegado a la puntuacion necesaria aun
            if (M[i-1] <= j && dardos[i][j] != dardos[i-1][j]) {
            // necesitamos un dardo en la zona i de la diana
                sol.push_back(M[i-1]); 
                j = j - M[i-1];
            } 
            else { // otro dardo en la zona i haria que nos pasasemos de puntos, asi que retrocedemos
            --i;
            }
        }
    }
    return sol;
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
   vector<int> sol = dardos_min(puntuaciones, valor);
   

   // escribir la solución


   if(sol.size() == 0) {
    printf("Imposible\n");
   }
   else {
    printf("%d:", sol.size());
    for(int i = 0; i < sol.size(); i++) {
        printf(" %d", sol[i]);
    }
    printf("\n");
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