
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Matriz.h"
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

#define COLS 5
#define ROWS 5

int chartoint(const char &c) {
   int resul = -1;
   switch(c){
      case 'A':
         resul = 0;
         break;
      case 'C':
         resul = 1;
         break;
      case 'G':
         resul = 2;
         break;
      case 'T':
         resul = 3;
         break;
      case '-':
         resul = 4;
         break;
   }
   return resul;
}

int recursion(const Matriz<int> &m, const Matriz<int> &v, const string &s1, const string &s2, int i, int j) {
   
   //caso base
   if(i == m.numfils() && j == m.numcols()) {
      return 0;
   }
   else if(i == m.numfils()-1 ) {

      int res = v[chartoint(s1[i])][chartoint(s2[j])];
      j++;
      for(;j < m.numcols();j++) {
         res += v[4][chartoint(s2[j])];
      }
      return res;
   }
   else if(j == m.numcols()-1) {

      int res = v[chartoint(s1[i])][chartoint(s2[j])];
      i++;
      for(;i < m.numfils();i++) {
         res += v[chartoint(s1[i])][4];
      }
      return res;
   }
   
   //caso recursivo
   int current = v[chartoint(s1[i])][chartoint(s2[j])] + recursion(m,v,s1,s2, i+1, j+1);
   int right= recursion(m,v,s1,s2, i, j+1) + v[4][chartoint(s2[j])];
   int down = recursion(m,v,s1,s2, i+1, j)+ v[chartoint(s1[i])][4];
   int resul= max( current, max(right,down) );

   return resul;
}

void resuelveCaso() {
   Matriz<int> V(ROWS, COLS, 0);
   for(int i = 0; i < ROWS; i++) {
      for(int j = 0; j < COLS; j++) {
         int a;
         cin >> a;
         V[i][j] = a;
      }
   }
   // matriz de valores inicializada
   int parejas;
   cin >> parejas;
   for(int pareja = 0; pareja < parejas; pareja++) {
      string s1, s2;
      cin >> s1 >> s2;
      Matriz<int> m(s1.size(),s2.size(), 0);

      int resul = recursion(m, V, s1, s2, 0, 0);
      cout << resul << "\n";
   }
   
   // leer los datos de la entrada
   
   // resolver el caso posiblemente llamando a otras funciones
   
   // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
