
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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
typedef struct {
    int cantidadChorizo;
    int gChorizo;
    int gPan;
    int precio;
} tBollo;

int beneficio(vector<tBollo> const& M, int C) { //rethink
    int n = M.size();
    Matriz<int> bollos(n+1, C+1, 0);
    //bollos[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        ///bollos[i][0] = 0;
        for (int j = 1; j <= C; ++j) {
            if (M[i-1].gPan > j) {
                bollos[i][j] = bollos[i-1][j];
            }
            else { // falta añadir constrain de que no hay chorizo infinito
                int up = bollos[i-1][j];
                int up_left = 0;
                int left = 0;
                if(M[i-1].gPan <= i) {
                    up_left = bollos[i-1][j - M[i-1].gPan];
                    left = bollos[i][j - M[i-1].gPan];

                    if( (j/M[i-1].gPan)*M[i-1].gChorizo <= M[i-1].cantidadChorizo) // si hay suficiente chorizo como para hacer otro bollo lo añadimos, si no, solo nos movemos en la matriz
                    {
                        up_left += M[i-1].precio;
                        left += M[i-1].precio;
                    }
                    else {
                        left += bollos[i][j-(j/M[i-1].gPan)]; // esto no funciona
                    }
                }

                bollos[i][j] = max( up, max(up_left, left) );
            }
            
        }
    }
    return bollos[n][C];
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    int N, gMasa;
    cin >> N >> gMasa;
    if (!std::cin){  // fin de la entrada
        return false;
    }

    vector<tBollo> b(N);
    for(int i = 0; i < N; i++) {
        int gTotal, gChorizo, gPan, precio;
        cin >> gTotal >> gChorizo >> gPan >> precio;

        b[i].cantidadChorizo = gTotal;
        b[i].gChorizo = gChorizo;
        b[i].gPan = gPan;
        b[i].precio = precio;
    }
    
    int bene = beneficio(b, gMasa);
   
    // escribir la solución
    cout << bene << "\n";

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