/*
Métodos algorítmicos en resolución de problemas
Problema 06
Maria José Belda Beneyto
Doble Grado en Ingeniería Infórmatica y Matemáticas
*/
#include <iostream>
#include "PriorityQueue.h"
using namespace std;

class Par {
public:
	long int id;
	int period;
	int periodOrig;

	bool operator< (Par const p)  const {
		if (period < p.period) return true;
		if (period == p.period) {
			if (id < p.id) return true;
		}
		return false;
	}
};

void resuelve(int n) {
	Par aux;
	PriorityQueue<Par> pq;
	long int idAux;
	int periodAux;
	for (int i = 0; i < n; i++) {
		cin >> idAux >> periodAux;
		aux.id = idAux;
		aux.period = periodAux;
		aux.periodOrig = periodAux;
		pq.push(aux);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		aux = pq.top();
		pq.pop();
		cout << aux.id << endl;
		aux.period += aux.periodOrig;
		pq.push(aux);
	}
	cout << "----" << endl;
}



int main() {
	int n;
	cin >> n;
	while (n != 0) {
		resuelve(n);
		cin >> n;
	}

	return 0;
}
