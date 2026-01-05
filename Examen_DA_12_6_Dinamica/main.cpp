#include <iostream>
#include <fstream>
#include "Matriz.h"
using namespace std;

#define COLUMNS 5
#define ROWS 5

//enum tAdn {A, C, G, T, MINUS};

int adnToInt(char c) {
   int resul = 0;
   switch(c) {
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

void resuelveCaso() {
   Matriz<int> valores(ROWS,COLUMNS,0);
   
   for(int i = 0; i < ROWS; i++) {
      for(int j = 0; j < COLUMNS; j++) {
         int valor;
         cin >> valor;
         valores[i][j] = valor;
      }
   }

   int numPares;
   cin >> numPares;


   string s1, s2;
   for(int k = 0; k < numPares; k++) {
      cin >> s1 >> s2;


      //creacion y recorrido de la matriz de soluciones parciales
      Matriz<int> m(s1.size()+1, s2.size()+1, 0);
      for(int i = 0; i < s1.size(); i++) {
         for(int j = 0; j < s2.size(); j++) {
            if(i == 0 && j == 0) {
               m[i][j] = 0;
            }
            else if(i == 0 || j == 0) {
               m[i][j] = -1*i - 1*j; // deberia poner -i en la primera fila y -j en la primera columna
            }
            else {
               // algoritmo
               int up = m[i-1][j];
               int left = m[i][j-1];
               int value = valores[adnToInt(s1[i])][adnToInt(s2[j])];
               int up_left = m[i-1][j-1];
               int puntos = max(left + up, value + up_left);
               m[i][j] = puntos;
            }
         }
      }

      cout << m[s1.size()][s2.size()] << "\n";
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
