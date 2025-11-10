
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
   
   queue<int> enemies;
   queue<int> allies;
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
   int storedTroops = 0;
   int deficit = 0;
   int result = 0;
   int enemyCity;
   int alliedTroops;
   

   queue<int> deficits;

   while(!enemies.empty()) {
      enemyCity = enemies.front();
      alliedTroops = allies.front();
      enemies.pop();
      allies.pop();

      if(enemyCity > alliedTroops) { // we asume the debt will be paid on later
         deficits.push(enemyCity - alliedTroops);
      }
      else { // if we have leftover troops
         storedTroops += (alliedTroops - enemyCity);
      }
      result++;

      while(!deficits.empty() && storedTroops > 0) { // if we had any deficit, and stored troops we reduce it 
         int difference = deficits.front() - storedTroops;
         if(difference <= 0){
            deficits.pop();
            storedTroops = -(difference);
         }
         else {
            deficits.front() -= storedTroops;
            storedTroops = 0;
         } 
      }
   }

   // if we weren't able to pay off the debt, we reduce the result by however many cities were in debt
   while(!deficits.empty()){
      result--;
      deficits.pop();
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
