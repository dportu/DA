#include "grafoValorado.h"
#include "priorityQueue.h"
#include "conjuntosDisjuntos.h"

using namespace std;

template <typename Valor>
class ARM_Kruskal {
    private:
    bool _conexo;
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    public:
    Valor costeARM() const {
        return coste;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), _conexo(false) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v,w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); 
                coste = max(a.valor(), coste);
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        if(cjtos.num_cjtos() == 1) {
            _conexo = true;
        }
    }
    bool conexo() {
        return _conexo;
    }
};