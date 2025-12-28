
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

typedef struct  {
    int pos;
    int vel;
    int turns;
}tZombie;

bool operator<(const tZombie &a, const tZombie &b) {
    return (a.turns < b.turns);
}

struct CompareZombies {
    bool operator()(tZombie const& z1, tZombie const& z2) {
        // Return true if z1 should be "lower priority" (pushed further down)
        // For a Min-Heap on 'turns', z1 is "lesser" if it has MORE turns.
        return z1.turns > z2.turns;
    }
};


bool resuelveCaso() {
   
   // leer los datos de la entrada
    int numZombies;
    cin >> numZombies;
    if (!std::cin){  // fin de la entrada
        return false;
    }

    vector<tZombie> zombies(numZombies);
    priority_queue<tZombie, vector<tZombie>, CompareZombies> q;
    for(int i = 0; i < numZombies; i++) {
        int p;
        cin >> p;

        zombies[i].pos = p;
    }
    for(int i = 0; i < numZombies; i++) {
        int v;
        cin >> v;
        zombies[i].vel = v;
        int turn;
        if(zombies[i].pos % zombies[i].vel != 0) {
            turn = zombies[i].pos / zombies[i].vel + 1;
        }
        else {
            turn = zombies[i].pos / zombies[i].vel;
        }
        zombies[i].turns = turn;
        q.push(zombies[i]);
    }

    //algoritmo voraz
    // vamos recorriendo la cola, manteniendo un contador que vamos actualizando al valorar cada zombie
    // para cada zombie, si el campo turns es menor o igual que el contador significa que daría tiempo a disparar al zombie antes de que llegara
    // en caso contrario significa que no daria tiempo y por tanto habriamos acabado

    int count = 0;
    int i = 0;
    bool dead = 0;
    while(count < numZombies && !dead) {
        tZombie z = q.top();
        q.pop();


        if(count < z.turns) {
            count++;
        }
        else {
            dead = true;
        }

    }
   
   // escribir la solución
   cout << count << "\n";

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