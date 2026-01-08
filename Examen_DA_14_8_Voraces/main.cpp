
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

typedef struct {
   int ini;
   int fin;
} tActividad;

bool operator<(const tActividad &a, const tActividad &b) {
   return a.ini < b.ini;
}

int iterate(const vector<int> &v, int inicio) {
   int i = 0;
   bool found = false;
   while(i < v.size() && !found) {
      if(inicio >= v[i]) {
         found = true;
      }
      else {
         i++;
      }
   }
   return i;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N;
   cin >> N;
   if (N == 0)
      return false;
   // resolver el caso posiblemente llamando a otras funciones
   PriorityQueue<tActividad> q;
   for(int i = 0; i < N; i++) {
      int inicio, final;
      cin >> inicio >> final;
      q.push({inicio,final});
   }

   vector<int> v;
   PriorityQueue<int> q2;
   int count = 0;
   q2.push(q.top().fin);
   q.pop();
   while(!q.empty()) {
      tActividad a = q.top();
      q.pop();
      

      int amigo = q2.top();
      if(a.ini >= amigo) {
         q2.pop();
      }
      else {
         count++;
      }
      q2.push(a.fin);
      /*int amigo = iterate(v, a.ini);
      if(amigo >= v.size()) {
         v.push_back(a.fin);
      }
      else {
         v[amigo] = a.fin;
      }*/
   }

   // escribir la solución
   cout << count << "\n";

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
