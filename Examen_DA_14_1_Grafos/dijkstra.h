#include "digrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

template <typename Valor>
class Dijkstra {
    public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
    dist(g.V(), INT_MAX), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
            relajar(a);
        }
    }
    bool hayCamino(int v) const { 
        return dist[v] != INT_MAX;
    }
    Valor distancia(int v) const { return dist[v]; }
    
    private:
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        int maxi = max(a.valor(), dist[v]);
        if (dist[w] > maxi) {
            dist[w] = maxi;
            ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};