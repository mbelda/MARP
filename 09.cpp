#include <iostream>
#include "ConjuntosDisjuntos.h"
#include <algorithm>
using namespace std;

int main() {
	int nCasos, nAmigos, nPersonas;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++) {
		cin >> nPersonas >> nAmigos;
		//Primero nadie es amigo de nadie
		ConjuntosDisjuntos cd = ConjuntosDisjuntos(nPersonas);
		int a, b;
		for (int j = 0; j < nAmigos; j++) {
			cin >> a >> b;
			//Marcamos a y b como amigos
			cd.unir(a - 1, b - 1);
		}
		//Devolvemos el tamaño de la cc mas grande
		int m = 0;
		for (int k = 0; k < nPersonas; k++) {
			m = max((int)cd.size(k), m);
		}
		cout << m << endl;
	}

	return 0;
}