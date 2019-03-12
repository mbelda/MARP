/*
Métodos algorítmicos en resolución de problemas
Problema 07
Maria José Belda Beneyto
Doble Grado en Ingeniería Infórmatica y Matemáticas
*/
#include <iostream>
#include "PriorityQueue.h"
using namespace std;


void resuelve(long int primero, int parejas) {
	long int p1, p2;
	PriorityQueue<long int> pqmin, pqmax;
	for (int i = 0; i < parejas; i++) {
		if (i != 0) cout << " ";
		cin >> p1 >> p2;

		if (p1 < primero && primero < p2) { //Uno a cada lado, no cambia el primero
			pqmax.push(-p1);
			pqmin.push(p2);
		} else if (p2 < primero && primero < p1) { //Uno a cada lado, no cambia el primero
			pqmax.push(-p2);
			pqmin.push(p1);
		} else if (p1 < primero && p2 < primero) { //Los dos mas pequeños
			pqmin.push(primero);
			pqmax.push(-p1);
			pqmax.push(-p2);
			primero = -pqmax.top(); //El mas grande de entre los pequeños
			pqmax.pop();
		} else { //Los dos mas grandes
			pqmax.push(-primero);
			pqmin.push(p1);
			pqmin.push(p2);
			primero = pqmin.top(); //El mas pequeño de entre los grandes
			pqmin.pop();
		}

		cout << primero;
	}
	cout << endl;
}

int main() {
	long int primero;
	int parejas;
	cin >> primero >> parejas;
	while (primero != 0 && parejas != 0) {
		resuelve(primero, parejas);
		cin >> primero >> parejas;
	}
	return 0;
}