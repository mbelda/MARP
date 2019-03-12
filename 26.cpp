//Alienigena infiltrado

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "PriorityQueue.h"
using namespace std;

struct tIntervalo {
	int a;
	int b;
};

bool menor(tIntervalo p, tIntervalo q) {
	return p.a < q.a;
}


void resuelve(int C, int F, long int N) {

	vector<tIntervalo> trabajos = vector<tIntervalo>();
	tIntervalo p;
	for (long int i = 0; i < N; i++) {
		cin >> p.a >> p.b;
		trabajos.push_back(p);
	}

	sort(trabajos.begin(), trabajos.end(), menor); //De menor a mayor


	int usados = 0;
	int izq = C, der = C;
	bool hayAlguno = false;
	for (int i = 0; i < N && der < F; i++) {
		if (trabajos[i].a <= izq) { //No deja hueco
			if (trabajos[i].b > der) { //Cubre mas que el que ya teniamos
				der = trabajos[i].b;
				hayAlguno = true;
				//no podemos hacer usados++ pq necesitamos encontrar el mejor
			}
		}
		else { 
			if (hayAlguno) { 
				hayAlguno = false;
				usados++;
				izq = der;//Lo ponemos y vuelta a empezar desde el que hemos elegido.b
				i--; //Quitamos la iteracion del bucle que acabamos de usar
			} else break; //Si no hay ninguno nos dejan todos huecos luego es imposible
		}
	}
	if (hayAlguno) usados++; //Nos hemos podido dejar el ultimo si hemos salido del bucle por la condicion i< Ns

	if (der < F) cout << "Imposible" << endl;
	else cout << usados << endl;
}


int main() {
	int C, F;
	long int N;
	cin >> C >> F >> N;
	while (C != 0 || F != 0 || N != 0) {
		resuelve(C,F,N);
		cin >> C >> F >> N;
	}
	return 0;
}