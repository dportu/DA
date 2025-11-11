/*
We need to for each enemy city, look for the lowest allied force that is able to fight them
*/
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
bool resuelveCaso() {
   
   // leer los datos de la entrada
   
   // N ciudades
   int N;
   cin >> N;

   if (!std::cin) {  // fin de la entrada
      return false;
   }
   
   priority_queue<int> enemies;
   priority_queue<int> allies;
   for(int i = 0; i < N; i++) {
      int city;
      cin >> city;
      enemies.push(city);
   }
   for(int i = 0; i < N; i++) {
      int city;
      cin >> city;
      allies.push(city);
   }
   
   

   // Solucionamos
   int result = 0;
   int enemyCity;
   int alliedTroops;
   


   while(!enemies.empty()) {
      enemyCity = enemies.top();
      alliedTroops = allies.top();
      enemies.pop();

      if(enemyCity > alliedTroops) { // we can't fight this
         
      }
      else { // we can win
         result++;
         allies.pop();
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
