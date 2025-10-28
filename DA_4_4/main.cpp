#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include "grafo.h"
#include "caminoMasCorto.h"
using namespace std;


bool resuelveCaso() {
   bool kevin = false;
   int p;
   // leer los datos de la entrada
   cin >> p;
   if (!std::cin) {
      return false;
   }  // fin de la entrada
   
   map<string,int> cine;
   int count = 0;

   Grafo g(0);

   for(int i = 0; i<p;i++) {
      string nombrePelicula;
      int keyPelicula;
      int numActores;

      cin >> nombrePelicula >> numActores;

      g.addV();
      cine.insert({nombrePelicula,count});
      keyPelicula = count;
      count++;

      for(int j = 0; j < numActores; j++) {
         string actor;
         cin >> actor;
         if(actor == "KevinBacon") {
            kevin = true;
         }
         ///si el actor no esta previamente en el grafo, lo aniadimos y creamos arista entre la pelicula y el actor
         if(cine.find(actor) == cine.end()) {
            cine.insert({actor, count});
            g.addV();
            g.ponArista(keyPelicula, count);
            count++;
         }
         else { // si el actor ya estaba en el grafo, solamente creamos la arista con la pelicula
            g.ponArista(keyPelicula, cine.at(actor));
         }
      }
   }

   
   int nActores;
   cin >> nActores;
   queue<string> q;
   for(int i = 0; i < nActores; i++) {
      string a;
      cin >> a;
      q.push(a);
   }
   
   // escribir la solución
   if(kevin) {
      CaminoMasCorto camino(g, cine["KevinBacon"]);
      for(int i = 0; i < nActores; i++) {
         int idActor = cine[q.front()];
         if(camino.hayCamino(idActor)) { // si hay camino desde kevin bacon hasta el actor que nos piden
            cout << q.front() << " " << camino.distancia(idActor) / 2 << "\n";
         }
         else {
            cout << q.front() << " INF\n";
         }
         q.pop();
      }
      cout << "---\n";
   }
   else {
      for(int i = 0; i < nActores; i++) {
         cout << q.front() << " INF\n";
         q.pop();
      }
      cout << "---\n";
   }
   

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
