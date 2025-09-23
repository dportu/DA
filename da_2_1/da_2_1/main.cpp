
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


bool resuelveCaso() {
   
   // leer los datos de la entrada
   int N;
   int n;
   int suma = 0;
   
   cin >> N; 
   
   if (N == 0)
      return false;
   
   priority_queue<int, vector<int>, greater<int>> q;

   for(int i = 0; i < N; i++) {
      cin >> n;
      q.push(n);
   }
   // resolver el caso posiblemente llamando a otras funciones
   if (N != 1) {

       for (int i = 0; i < N; i++) {
           int a = q.top();
           q.pop();
          int b = q.top();
          q.pop();
           suma = (a + b);
          q.push(suma);
       }
   }
   /*
   * visualizacion de las colas
   for(int i=0;i<N;i++){
      cout << q.top() << ' ';
      q.pop();
   }
   cout << '\n';*/


   // escribir la solución
   cout << suma << '\n';

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
