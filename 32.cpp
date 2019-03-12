//Relaciones

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

bool resuelve() {
	int nPersonas, nRelaciones;
	cin >> nPersonas >> nRelaciones;
	if (!cin) return false;

	vector<vector<int>> sol(nPersonas, vector<int>(nPersonas, nPersonas + 1));
	string p1, p2;
	map<string, int> nombres;
	int cont = 0;
	for (int i = 0; i < nRelaciones; i++) {
		cin >> p1 >> p2;
		auto it1 = nombres.find(p1);
		if (it1 == nombres.end()) {
			//El nombre p1 no esta
			it1 = nombres.insert(pair<string, int>(p1, cont)).first;
			cont++;
		}
		auto it2 = nombres.find(p2);
		if (it2 == nombres.end()) {
			//El nombre p2 no esta
			it2 = nombres.insert(pair<string, int>(p2, cont)).first;
			cont++;
		}
		sol[it1->second][it2->second] = 1;
		sol[it2->second][it1->second] = 1;
	}
	for (int i = 0; i < nPersonas; i++) {
		sol[i][i] = 0;
	}

	int maxAristas = 0;
	for (int k = 0; k < nPersonas; k++) {
		maxAristas = 0;
		for (int i = 0; i < nPersonas; i++) {
			for (int j = 0; j < nPersonas; j++) {
				sol[i][j] = min(sol[i][j], sol[i][k] + sol[k][j]);
				maxAristas = max(maxAristas, sol[i][j]);
			}
		}
	}

	if (maxAristas > nPersonas) {
		cout << "DESCONECTADA" << endl;
	}
	else {
		cout << maxAristas << endl;
	}

	return true;
}


int main() {
	while (resuelve()) {}
	return 0;
}