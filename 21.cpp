//Telesilla

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelve() {
	int maximo, gente;
	cin >> maximo >> gente;
	if (!cin) return false;

	vector<int> pesos = vector<int>();
	int a;
	for (int i = 0; i < gente; i++) {
		cin >> a;
		pesos.push_back(a);
	}

	sort(pesos.begin(), pesos.end()); //De menor a mayor

	int sillas = 0;
	vector<bool> marked = vector<bool>(gente, false);

	for (int i = gente - 1; i >= 0; i--) {
		if (!marked[i]) {
			sillas++;
			marked[i] = true;
			//Buscamos la pareja mas pesada posible
			int aux = -1;
			for (int j = 0; j < i; j++) {
				if (!marked[j] && pesos[i] + pesos[j] <= maximo) {
					aux = j;
				}
				else if (pesos[i] + pesos[j] > maximo) break;
			}
			if (aux >= 0) { //Hemos encontrado pareja
				marked[aux] = true;
			}
		}
	}

	cout << sillas << endl;
	return true;
}


int main() {
	while (resuelve()) {}
	return 0;
}
