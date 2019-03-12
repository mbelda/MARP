//Cometa

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct tCuerda {
	int largo;
	int coste;
};

struct tSol {
	long int nFormas;
	long int minCoste;
	long int nCuerdas;
};

bool resuelve() {
	int N, L;
	cin >> N >> L;
	if (!cin) return false;

	vector<tCuerda> cuerdas = vector<tCuerda>();
	int l, c;
	tCuerda cuerda;
	for (int i = 0; i < N; i++) {
		cin >> l >> c;
		cuerda.largo = l;
		cuerda.coste = c;
		cuerdas.push_back(cuerda);
	}

	vector<tSol> sol = vector<tSol>(L+1);
	for (int i = 1; i <= L; i++) {
		sol[i].nFormas = 0;
		sol[i].minCoste = 0;
		sol[i].nCuerdas = 0;
	}
	sol[0].nFormas = 1;
	sol[0].minCoste = 0;
	sol[0].nCuerdas = 0;

	for (int i = 0; i < N; i++) {
		for (int j = L; j >= cuerdas[i].largo; j--) {

			if (j - cuerdas[i].largo >= 0) { //La cuerda i-esima no es demasiado grande
				sol[j].nFormas += sol[j - cuerdas[i].largo].nFormas;

				if (sol[j - cuerdas[i].largo].nFormas != 0) { //Si sol[j-cuerdas[i].largo] se puede construir

					if(sol[j - cuerdas[i].largo].nFormas == sol[j].nFormas) {
						//Si sol[j].nFormas era 0, no podiamos construirlo, ahora si, actualizamos valors
						sol[j].minCoste = sol[j - cuerdas[i].largo].minCoste + cuerdas[i].coste;
						sol[j].nCuerdas = sol[j - cuerdas[i].largo].nCuerdas + 1;
					}
					else {
						sol[j].minCoste = min(sol[j].minCoste,
							sol[j - cuerdas[i].largo].minCoste + cuerdas[i].coste);
						sol[j].nCuerdas = min(sol[j].nCuerdas,
							sol[j - cuerdas[i].largo].nCuerdas + 1);

					}
				}
					
			}
		}
	}


	if (sol[L].nFormas == 0) cout << "NO" << endl;
	else  cout	<< "SI " << sol[L].nFormas
				<<" " << sol[L].nCuerdas
				<<" " << sol[L].minCoste << endl;
	return true;
}


int main() {
	while (resuelve()) {}
	return 0;
}