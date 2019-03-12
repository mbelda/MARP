/*
Métodos algorítmicos en resolución de problemas
Problema 08
Maria José Belda Beneyto
Doble Grado en Ingeniería Infórmatica y Matemáticas
*/
#include <iostream>
#include "PriorityQueue.h"
using namespace std;

class Cuerda {
public:
	int partituras;
	int musicos;

	//Esta al reves para que cuadre pq la PriorityQueue
	//es de minimos y la necesito de maximos
	bool operator< (Cuerda c) const {
		int sol1 = (musicos / partituras);
		int sol2 = (c.musicos / c.partituras);
		if (musicos % partituras != 0) sol1++;
		if (c.musicos % c.partituras != 0) sol2++;
		if (sol1 <= sol2) return false;
		return true;
	}
};

bool resuelve() {
	int p, n, auxP;
	cin >> p >> n;
	if (!cin) return false;
	Cuerda aux;
	PriorityQueue<Cuerda> pq; //Max
	for (int i = 0; i < n; i++) {
		cin >> aux.musicos;
		aux.partituras = 1; //Repartimos una partitura por cuerda
		pq.push(aux);
	}
	auxP = p - n; //Las partituras que nos quedan
	while (auxP > 0) {
		//Le compramos otra al instrumento que mas lleno este
		aux = pq.top();
		pq.pop();
		aux.partituras++;
		pq.push(aux);
		auxP--;
	}
	int auxx = pq.top().musicos % pq.top().partituras;
	if(auxx == 0) cout << pq.top().musicos / pq.top().partituras << endl;
	else cout << pq.top().musicos / pq.top().partituras + 1 << endl;
	return true;
}

int main() {
	
	while (resuelve()) {}
	return 0;
}