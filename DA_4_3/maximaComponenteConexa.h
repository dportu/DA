#include "grafo.h"
using namespace std;


class MaximaCompConexa {
    private:
    vector<bool> _visit; // visit[v] = se ha visitado el vértice v?
    int _maxim; // tamaño de la componente mayor
    int dfs(Grafo const& g, int v) {
        _visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!_visit[w])
            tam += dfs(g, w);
        }
        return tam;
    }
    
    public:
    MaximaCompConexa(Grafo const& g) : _visit(g.V(), false), _maxim(0) {
    for (int v = 0; v < g.V(); ++v) {
        if (!_visit[v]) { // se recorre una nueva componente conexa
                int tam = dfs(g, v);
                _maxim = max(_maxim, tam);
            }
        }
    }
    // tamaño máximo de una componente conexa
    int maximo() const {
        return _maxim;
    }
    
};