// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
#include <vector>
using namespace std;

bool casoDePrueba() {

  
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
                result = false;
            }
            else {
                previous = v[i];
                count++;
            }

            i--;
        }
    }
    printf("%d\n", result);

    return false;
} // casoDePrueba

int main() {

  while(casoDePrueba());

  return 0;

} // main
