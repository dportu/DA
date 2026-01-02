#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
#include "grafoValorado.h"
#include "conjuntosDisjuntos.h"
using namespace std;

template <typename Valor>
class ARM_Kruskal {
    private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    // new
    bool _conexo;
    int _maxValue;

    public:
    //new
    int maxValue() {
        return _maxValue;
    }
    int conexo() {
        return _conexo;
    }

    Valor costeARM() const {
        return coste;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), _maxValue(0), _conexo(false) {

        //_maxValue = 0;
        //_numVertices = 0;
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v,w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); 
                coste += a.valor();
                if (_ARM.size() == g.V() - 1) {
                    _conexo = true;

                    break;
                } 
            }

            if(a.valor() > _maxValue) {
                _maxValue = a.valor();
            }
        }
    }
};