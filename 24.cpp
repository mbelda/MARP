//Peliculas

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct tPelicula {
	int ini;
	int fin;
};

bool menor(tPelicula a, tPelicula b) {
	return a.fin < b.fin;
}

void resuelve(int nCasos) {
	
	vector<tPelicula> peliculas = vector<tPelicula>();
	tPelicula p;
	string str;
	int horas, minutos;
	int dur;
	for (int i = 0; i < nCasos; i++) {
		cin >> str >> dur;
		horas = stoi(str.substr(0, 2));
		minutos = stoi(str.substr(3, 2));
		p.ini = horas * 60 + minutos;
		p.fin = p.ini + dur;
		peliculas.push_back(p);
	}

	sort(peliculas.begin(), peliculas.end(), menor); //De menor a mayor

	
	int ocupado = peliculas[0].fin + 10;
	int nPelis = 1;

	for (int i = 1; i < nCasos; i++) {
		if (ocupado <= peliculas[i].ini) {
			ocupado = peliculas[i].fin + 10;
			nPelis++;
		}
	}

	cout << nPelis << endl;
}


int main() {
	int nCasos;
	cin >> nCasos;
	while (nCasos != 0) {
		resuelve(nCasos);
		cin >> nCasos;
	}
	return 0;
}
