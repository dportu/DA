
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
bool resuelveCaso() {
   
   // leer los datos de la entrada
   
   // N de agujeros, L de longitud de los parches
   int N, L;
   cin >> N >> L;

   if (!std::cin) {  // fin de la entrada
      return false;
   }
   
   queue<int> agujeros;

   for(int i = 0; i < N; i++) {
      int agujero;
      cin >> agujero;
      agujeros.push(agujero);
   }

   // Solucionamos
   int current = agujeros.front();
   agujeros.pop();
   int result = 1;
   int maxDist = L;

   while(!agujeros.empty()) {
      int next = agujeros.front();
      agujeros.pop();

      if((next - current) > maxDist) {
         result++;
         maxDist = L;
      }
      else {
         maxDist -= (next - current);
      }

      current = next;
   }


   // escribir la solución
   printf("%d\n", result);

   return true;
}
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
