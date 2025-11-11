#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N, M;
   cin >> N >> M;
   
   if (!std::cin) { // fin de la entrada
      return false;
   }
   
   priority_queue<int> jugadores;
   priority_queue<int> equipaciones;

   for(int i = 0; i < N; i++){
      int tallaJugador;
      cin >> tallaJugador;
      jugadores.push(tallaJugador);
   }
   for(int i = 0; i < M; i++) {
      int equipacion;
      cin >> equipacion;
      equipaciones.push(equipacion);
   }



   // Solucionamos
   int result = 0;
   while(!jugadores.empty()) {
      int tallaJugador = jugadores.top();
      jugadores.pop();
      
      while( !equipaciones.empty() && (equipaciones.top() > tallaJugador + 1) ) {
         equipaciones.pop();
      }
      if( equipaciones.empty() || (equipaciones.top() < tallaJugador) ) {
         result++;
      }
      else if ( equipaciones.top() == tallaJugador || equipaciones.top() == (tallaJugador + 1)) {
         equipaciones.pop();
      }
      
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
