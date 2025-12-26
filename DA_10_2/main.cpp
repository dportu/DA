// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool resuelveCaso() {

  
  int N; // # of elements

  cin >> N;

  if (N == 0)
    return false;

    // vector initialization
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        int elem;
        cin >> elem;
        v[i] = elem;
    }

    bool result = true;
    int count = 1;
    // trivial case
    if(N == 1) {
    }
    else {
        // algorithm
        int previous = v.back();
        int i = N-2;
        while(result && i >= 0) {
            if(v[i] > previous) {
                result = true;
            }
            else {
                previous = v[i];
                count++;
            }

            i--;
        }
    }

    if(count < N) {
        count--;
    }
    printf("%d\n", count);

    return true;
} // casoDePrueba

int main() {

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


} // main
