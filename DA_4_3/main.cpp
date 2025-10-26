#include <iostream>
#include <fstream>
#include "grafo.h"
#include "maximaComponenteConexa.h"
#include "manchas.h"
using namespace std;



bool resuelveCaso() {
   int F, C;
   cin >> F >> C; // número de filas y columnas
   if (!cin) return false;
   Mapa mapa(F);
   // leemos la imagen
   for (string & linea : mapa)
   cin >> linea;
   // la analizamos
   Manchas manchas(mapa);
   cout << manchas.numero() << ' ' << manchas.maximo() << '\n';
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
