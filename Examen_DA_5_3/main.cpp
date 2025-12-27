
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
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

const int MAX = 10000;
const int INF = 1000000000; // ∞

int calc(int x, int a, int b, int mod) {
    return (x*a+b)%mod;
}

int bfs(int origen, int destino, int mod, const vector<pair<int,int>> &&ops) {
    if (origen == destino) return 0;
    vector<int> distancia(ops.size(), INF);
    distancia[origen] = 0;
    queue<int> cola; 
    cola.push(origen);
    while (!cola.empty()) {
        int v = cola.front(); 
        cola.pop();
        for (int i = 0; i < 3; ++i) {
            int w = calc(v, ops[i].first, ops[i].second, mod);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == destino)
                {   
                    return distancia[w];
                }
                else
                {   
                    cola.push(w);
                }
            }
        }
    }
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    int M, S, T, N;

    cin >> M >> S >> T >> N;
   
    if (!std::cin){  // fin de la entrada
        return false;
    }

    vector<pair<int,int>>ops(N);
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        ops[i].first = a;
        ops[i].second = b;
    }

   // resolver el caso posiblemente llamando a otras funciones
   
   // escribir la solución

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
