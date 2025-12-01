#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


bool resuelveCaso() {
   
   // leer los datos de la entrada
   int n; 
   cin >> n;
   if (n == 0) {
      return false;
   }
   
   vector<pair<int,int>> timetable;
   for(int i = 0; i < n; i++) {
      string time;
      cin >> time;
      int hours = stoi(time.substr(0, 2));
      int minutes = stoi(time.substr(3, 2));
      int duration;
      cin >> duration;
      duration += 10;
      minutes += 60 * hours;

      timetable.push_back({minutes, duration});
      sort(timetable.begin(), timetable.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
             return a.second < b.second;  // ascending order
         });

     // sort(timetable.cbegin(), timetable.cend(),)

   }

   int result = 1;
   auto it = timetable.cbegin();
   pair<int,int> current = timetable.front();
   it++;
   while(it != timetable.cend()) {
      if(it->first >= (current.first + current.second)) {
         current = timetable.front();
         result++;
      }
      timetable.pop();
   }
   // escribir la solucion
   printf("%d\n", result);

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
