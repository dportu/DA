#include <iostream>
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
#include <algorithm>

template <typename Valor>
class ARM_Kruskal {
private:
	std::vector<Arista<Valor>> _ARM;
	Valor coste;
	int _maximaLiana = 0;
public:
	Valor costeARM() const {
		return coste;
	}
	std::vector<Arista<Valor>> const& ARM() const {
		return _ARM;
	}
	int maximaLiana() {
		return _maximaLiana;
	}
	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0) {
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				_ARM.push_back(a); coste += a.valor();
				_maximaLiana = std::max(_maximaLiana, a.valor());
				if (_ARM.size() == g.V() - 1) break;
			}
		}
	}
};