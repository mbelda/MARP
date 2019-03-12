//Conferencias

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "PriorityQueue.h"
using namespace std;

struct tPelicula {
	int ini;
	int fin;
};

bool menor(tPelicula a, tPelicula b) {
	return a.ini < b.ini;
}

void resuelve(long int nCasos) {

	vector<tPelicula> peliculas = vector<tPelicula>();
	tPelicula p;
	for (long int i = 0; i < nCasos; i++) {
		cin >> p.ini >> p.fin;
		peliculas.push_back(p);
	}

	sort(peliculas.begin(), peliculas.end(), menor); //De menor a mayor
	
	PriorityQueue<int> salas = PriorityQueue<int>();
	
	for (long int i = 0; i < nCasos; i++) {
		if (!salas.empty() && salas.top() <= peliculas[i].ini) {
			salas.pop();
		}
		salas.push(peliculas[i].fin);
	}

	cout << salas.size() << endl;
}


int main() {
	long int nCasos;
	cin >> nCasos;
	while (nCasos != 0) {
		resuelve(nCasos);
		cin >> nCasos;
	}
	return 0;
}