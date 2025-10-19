#include <vector>
#include "grafo.h"
using namespace std;

class CaminosDFS {
    private:
        vector<bool> visit; //visit[v] = hay camino de s a v?
        vector<int> ant; //ant[v] = vertice anterior al llegar a v
        int s; //vertice origen

        void dfs(Grafo const& g, int v) {
            visit[v] = true;
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v;
                    dfs(g, w);
                }
            }
        }

    public:
        //inicializamos el caminosDFS con un vector visit de tamanio g.V() a false,
        //un vector ant de tamanio g.V()  
        //y con un origen s
        CaminosDFS(Grafo const& g, int s) : visit(g.V(), false), ant(g.V()), s(s) {
            dfs(g, s);
        }

        bool conexo () {
            int i = 0;
            while (visit[i]) {
                i++;
            }

            return i == visit.size();
        }
};