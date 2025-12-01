
/*@ <answer>
*
* Nombre y Apellidos: Daniel Portuondo Rodriguez
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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

struct tObjeto { 
   int profundidad; 
   double valor; 
};

double calc_valor(vector<tObjeto> const& obj, int objeto, int segundos, Matriz<double> & valores) {
      if (valores[objeto][segundos] != -1){ // subproblema ya resuelto
         return valores[objeto][segundos];
      }
      if (objeto == 0 || segundos == 0) {
         valores[objeto][segundos] = 0;
      }
      else if ((3 * obj[objeto-1].profundidad) > segundos) {
         valores[objeto][segundos] = calc_valor(obj, objeto-1, segundos, valores);
      }
      else {
         double up = calc_valor(obj, objeto-1, segundos, valores); // no cogemos
         double up_left = calc_valor(obj, objeto-1, segundos - 3*obj[objeto-1].profundidad, valores);
         double valor_actual = obj[objeto-1].valor;
         valores[objeto][segundos] = max(up, up_left + valor_actual);
      }
      
      return valores[objeto][segundos];
}
   
double tesoros(vector<tObjeto> const& objetos, int M, vector<bool> & sol, int & count) {
   int n = objetos.size();
   Matriz<double> botin(n+1, M+1, -1);
   double valor = calc_valor(objetos, n, M, botin);
   // cálculo de los objetos
   int i = n, j = M;
   sol = vector<bool>(n, false);
   while (i > 0 && j > 0) {
      if (botin[i][j] != botin[i-1][j]) {
         sol[i-1] = true;
         count++;
         j = j - 3*objetos[i-1].profundidad;
      }
      --i;
   }
   return valor;
}

bool cmp(const tObjeto obj1, const tObjeto obj2) {
   return ( (obj1.valor / obj1.profundidad) > (obj2.valor / obj2.profundidad) );
}
   
bool resuelveCaso() {
   
   // leer los datos de la entrada
   int segundos, numCofres;
   cin >> segundos >> numCofres;
   
   if (!std::cin){  // fin de la entrada
      return false;
   }
   // resolver el caso posiblemente llamando a otras funciones
   
   vector<tObjeto> objetos(numCofres);
   for(int i = 0; i < numCofres; i++) {
      int p;
      double v;
      cin >> p >> v;
      tObjeto obj = {p,v};
      objetos[i] = obj;
   }


   // Ordenamos de mayor a menor en funcion de la densidad ( valor / profundidad )
   sort(objetos.begin(), objetos.end(), cmp);
   

   vector<bool> sol;
   int count = 0;
   double valor = tesoros(objetos, segundos, sol, count);

   
   // escribir la solución
   cout << valor << "\n" << count << "\n";
   //printf("%d\n%d\n", valor, count);
   for(int i = 0; i < sol.size(); i++) {
      if(sol[i]) {
         //printf("%d %d\n", objetos[i].profundidad, objetos[i].valor);
         cout << objetos[i].profundidad << " " << objetos[i].valor << "\n";
      }
   }
   printf("---\n");
   
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
