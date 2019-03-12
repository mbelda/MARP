/*
Métodos algorítmicos en resolución de problemas
Problema 05
Maria José Belda Beneyto
Doble Grado en Ingeniería Infórmatica y Matemáticas
*/
#include <iostream>
#include "PriorityQueue.h"
using namespace std;

long int gorras(int n) {
	long int seg;
	PriorityQueue<long int> pq;
	for (int i = 0; i < n; i++) {
		cin >> seg;
		pq.push(seg);
	}
	seg = 0;
	while (pq.size() > 1) {
		long int eq1 = pq.top();
		pq.pop();
		long int eq2 = pq.top();
		pq.pop();
		pq.push(eq1 + eq2);
		seg += eq1 + eq2;
	}

	return seg;
}

int main() {
	int nEquipos;
	cin >> nEquipos;
	while (nEquipos != 0) {
		cout << gorras(nEquipos) << endl;
		cin >> nEquipos;
	}
	return 0;
}