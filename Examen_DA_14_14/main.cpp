
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "IndexPQ.h"
#include "PriorityQueue.h"
#include <queue>
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

int fibo(int a, int Z) {
   int res = 0;
   while(a >0) {
      res+= a;
      a -= Z;
   }
   return res;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int B;
   cin >> B;
   if (!std::cin)  // fin de la entrada
      return false;
   // resolver el caso posiblemente llamando a otras funciones
   vector<int> capacidades;
   
   int i = 0;
   for(; i < B; i++) {
      int capacidad;
      cin >> capacidad;
      //q.push(i, duracion);
      capacidades.push_back(capacidad);
   }
   int R;
   cin >> R;
   queue<pair<int,int>> q_repuesto;
   for(int j = 0; j < R; j++) {
      int capacidad_repuesto;
      cin >> capacidad_repuesto;
      q_repuesto.push({i,capacidad_repuesto});
      capacidades.push_back(capacidad_repuesto);
      i++;
   }
   IndexPQ<int> q(capacidades.size());
   for(int z = 0; z < B; z++) {
      q.push(z, capacidades[z]);
   }
   int Z , T;
   cin >> Z >> T;

   bool catastrofe = false;
   int time = 0;
   while(!catastrofe && time < T) {
      q.updateAll(1);
      if(q.empty()) {
         catastrofe = true;
      }
      else if(q.top().prioridad == 0) {
         while(q.top().prioridad == 0)
         if( (capacidades[q.top().elem] -= Z) <= 0) // la capacidad de la bateria es reducida tras la recarga
         {
            // sacamos la bateria ahora inutil y ponemos una nueva de repuesto si la hay
            q.pop();
            if(!q_repuesto.empty()) {
               int elem = q_repuesto.front().first;
               int capacidad = q_repuesto.front().second;
               q.push(elem, capacidad);
               q_repuesto.pop();
            }
         }
         else {
            // la bateria es recargada con exito (le queda capacidad aun) por lo que la volvemos a meter 
            int elem = q.top().elem;
            q.pop();
            q.push(elem,capacidades[elem]);
         }
         if(!q.empty()) {
            q.pop();
         }
      }

      time++;
   }


   if(q.empty()) {
      cout << "ABANDONEN INMEDIATEMENTE LA BASE\n";
   }
   else if(q.size() < B) {
      cout << "FALLO EN EL SISTEMA\n";
      while(!q.empty()) {
         cout << q.top().elem + 1 << " " << T + q.top().prioridad << "\n";
         q.pop();
      }
   }
   else if(q.size() == B){
      cout << "CORRECTO\n";
      while(!q.empty()) {
         cout << q.top().elem + 1<< " " << T + q.top().prioridad << "\n";
         q.pop();
      }
   }
   else {
      cout << "fallo en el codigo\n";
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
